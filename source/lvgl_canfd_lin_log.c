/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <string.h>
#include "fsl_sd.h"
#include "fsl_debug_console.h"
#include "ff.h"
#include "diskio.h"
#include "fsl_sd_disk.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "sdmmc_config.h"
#include "fsl_common.h"

#include "fsl_lpuart.h"
#include "lvgl_support.h"
#include "pin_mux.h"
#include "board.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_smartdma.h"
#include "fsl_inputmux_connections.h"
#include "fsl_inputmux.h"
#include "flexcanfd.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define I2C_RELEASE_SDA_PORT  PORT4
#define I2C_RELEASE_SCL_PORT  PORT4
#define I2C_RELEASE_SDA_GPIO  GPIO4
#define I2C_RELEASE_SDA_PIN   0U
#define I2C_RELEASE_SCL_GPIO  GPIO4
#define I2C_RELEASE_SCL_PIN   1U
#define I2C_RELEASE_BUS_COUNT 100U
/* 1 ms per tick. */
#ifndef LVGL_TICK_MS
#define LVGL_TICK_MS 1U
#endif

/* lv_task_handler is called every 5-tick. */
#ifndef LVGL_TASK_PERIOD_TICK
#define LVGL_TASK_PERIOD_TICK 5U
#endif

#define BUFFER_SIZE (513U)

/*******************************************************************************
 * Variables
 ******************************************************************************/
lv_ui guider_ui;
static volatile uint32_t s_tick        = 0U;
static volatile bool s_lvglTaskPending = false;

static status_t sdcardWaitCardInsert(void);
static FATFS g_fileSystem; /* File system object */
FIL g_fileObject;   /* File object */
FIL canfd_fileObject;   /* File object */
/*! @brief Data written to the card */
SDK_ALIGN(uint8_t g_bufferWrite[BUFFER_SIZE], BOARD_SDMMC_DATA_BUFFER_ALIGN_SIZE);
/*! @brief Data read from the card */
SDK_ALIGN(uint8_t g_bufferRead[BUFFER_SIZE], BOARD_SDMMC_DATA_BUFFER_ALIGN_SIZE);

#define LIN_COM2

#ifdef LIN_COM0
#define DEMO_LIN            LPUART0
#define DEMO_LIN_CLK_FREQ   12000000U
#define DEMO_LIN_IRQn       LP_FLEXCOMM0_IRQn
#define DEMO_LIN_IRQHandler LP_FLEXCOMM0_IRQHandler
#define DisableLinBreak LPUART0->STAT &= ~(LPUART_STAT_LBKDE_MASK);
#define EnableLinBreak  LPUART0->STAT |= LPUART_STAT_LBKDE_MASK;
#endif

#ifdef LIN_COM2
#define DEMO_LIN            LPUART2
#define DEMO_LIN_CLK_FREQ   12000000U
#define DEMO_LIN_IRQn       LP_FLEXCOMM2_IRQn
#define DEMO_LIN_IRQHandler LP_FLEXCOMM2_IRQHandler
#define DisableLinBreak LPUART2->STAT &= ~(LPUART_STAT_LBKDE_MASK);
#define EnableLinBreak  LPUART2->STAT |= LPUART_STAT_LBKDE_MASK;
#endif
/*! @brief Ring buffer size (Unit: Byte). */
#define DEMO_RING_BUFFER_SIZE 16



#define IDLE                0x00          /**< IDLE state */
#define SEND_BREAK          0x01          /**< Send break field state */
#define SEND_PID            0x02          /**< send PID state */
#define RECV_SYN            0x03          /**< receive synchronize state */
#define RECV_PID            0x04          /**< receive PID state */
#define IGNORE_DATA         0x05          /**< ignore data state */
#define RECV_DATA           0x06          /**< receive data state */
#define SEND_DATA           0x07          /**< send data state */
#define SEND_DATA_COMPLETED 0x08          /**< send data completed state */
#define PROC_CALLBACK       0x09          /**< proceduce callback state */
#define SLEEP_MODE          0x0A          /**< sleep mode state */
#define UNINIT              0xFF          /**< uninitialize state */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*
  Ring buffer for data input and output, in this example, input data are saved
  to ring buffer in IRQ handler. The main function polls the ring buffer status,
  if there are new data, then send them out.
  Ring buffer full: (((rxIndex + 1) % DEMO_RING_BUFFER_SIZE) == txIndex)
  Ring buffer empty: (rxIndex == txIndex)
*/
uint8_t demoRingBuffer[DEMO_RING_BUFFER_SIZE];
volatile uint16_t txIndex; /* Index of the data to send out. */
volatile uint16_t rxIndex; /* Index of the memory to save new arrived data. */
uint8_t rxbuff[20] = {0};
uint16_t cnt=0, recdatacnt=0;
uint8_t Lin_BKflag=0;
static uint8_t          state = UNINIT;

/*******************************************************************************
 * Code
 ******************************************************************************/

void DEMO_LIN_IRQHandler(void)
{
//    uint8_t data;
//    uint16_t tmprxIndex = rxIndex;
//    uint16_t tmptxIndex = txIndex;

    if (DEMO_LIN->STAT & LPUART_STAT_LBKDIF_MASK)
    {
    	DEMO_LIN->STAT |= LPUART_STAT_LBKDIF_MASK;// clear the bit
        Lin_BKflag = 1;
        cnt = 0;
        state = RECV_SYN;
        DisableLinBreak;
    }
    if (DEMO_LIN->STAT & LPUART_STAT_RDRF_MASK)
    {
      	 rxbuff[cnt] = (uint8_t)((DEMO_LIN->DATA) & 0xff);
		switch(state)
		{
		   case RECV_SYN:
			 if(0x55 == rxbuff[cnt])
			 {
				 state = RECV_PID;
			 }
			 else
			 {
				 state = IDLE;
				 DisableLinBreak;
			 }
			 break;
		   case RECV_PID:
			 if(0xAD == rxbuff[cnt])
			 {
				 state = RECV_DATA;
			 }
			 else if(0xEC == rxbuff[cnt])
			 {
				 state = SEND_DATA;
			 }
			 else
			 {
				 state = IDLE;
				 DisableLinBreak;
			 }
			 break;
		   case RECV_DATA:
			 recdatacnt++;
			 if(recdatacnt >= 4) // 3 Bytes data + 1 Bytes checksum
			 {
				 recdatacnt=0;
				 state = IDLE;
				 EnableLinBreak;
			 }
			 break;
		   default:break;
		}
		cnt++;

    }

    SDK_ISR_EXIT_BARRIER;
}

void uart_LIN_break( LPUART_Type *base )
{
	base->CTRL &= ~(LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK);   //Disable UART0 first
	base->STAT |= LPUART_STAT_BRK13_MASK; //13 bit times
	base->STAT |= LPUART_STAT_LBKDE_MASK;//LIN break detection enable
	base->BAUD |= LPUART_BAUD_LBKDIE_MASK;

	base->CTRL |= (LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK);
	base->CTRL |= LPUART_CTRL_RIE_MASK;
	EnableIRQ(DEMO_LIN_IRQn);
}
uint8_t LINCheckSum(uint8_t PID, uint8_t *buf, uint8_t lens);
uint8_t LINCalcParity(uint8_t id);
uint8_t sendbuffer[3] = {0x01, 0x02, 0x10};



/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_SetupTick(void);
#if LV_USE_LOG
static void print_cb(const char *buf);
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_I2C_ReleaseBus(void);


static void i2c_release_bus_delay(void)
{
    SDK_DelayAtLeastUs(100U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

extern sd_card_t g_sd;
static status_t sdcardWaitCardInsert(void)
{
    BOARD_SD_Config(&g_sd, NULL, BOARD_SDMMC_SD_HOST_IRQ_PRIORITY, NULL);

    /* SD host init function */
    if (SD_HostInit(&g_sd) != kStatus_Success)
    {
        PRINTF("\r\nSD host init fail\r\n");
        return kStatus_Fail;
    }

    /* wait card insert */
    if (SD_PollingCardInsert(&g_sd, kSD_Inserted) == kStatus_Success)
    {
        PRINTF("\r\nCard inserted.\r\n");
        /* power off card */
        SD_SetCardPower(&g_sd, false);
        /* power on the card */
        SD_SetCardPower(&g_sd, true);
    }
    else
    {
        PRINTF("\r\nCard detect fail.\r\n");
        return kStatus_Fail;
    }

    return kStatus_Success;
}

int sd_savecsv_header( void )
{

	FRESULT error;
	DIR directory; /* Directory object */
	FILINFO fileInformation;
	UINT bytesWritten;
	UINT bytesRead;
	const TCHAR driverNumberBuffer[3U] = {SDDISK + '0', ':', '/'};
	volatile bool failedFlag           = false;
	char ch                            = '0';
	BYTE work[FF_MAX_SS];
	uint8_t filewritelength;

	PRINTF("\r\nFATFS example to demonstrate how to use FATFS with SD card.\r\n");
	PRINTF("\r\nPlease insert a card into board.\r\n");

	if (sdcardWaitCardInsert() != kStatus_Success)
	{
		return -1;
	}

	if (f_mount(&g_fileSystem, driverNumberBuffer, 0U))
	{
		PRINTF("Mount volume failed.\r\n");
		return -1;
	}

	#if (FF_FS_RPATH >= 2U)
	error = f_chdrive((char const *)&driverNumberBuffer[0U]);
	if (error)
	{
		PRINTF("Change drive failed.\r\n");
		return -1;
	}
	#endif

	#if 0//FF_USE_MKFS
	PRINTF("\r\nMake file system......The time may be long if the card capacity is big.\r\n");
	if (f_mkfs(driverNumberBuffer, 0, work, sizeof work))
	{
		PRINTF("Make file system failed.\r\n");
		return -1;
	}
	#endif /* FF_USE_MKFS */


	PRINTF("\r\nCreate directory......\r\n");
	error = f_mkdir(_T("/logs"));
	if (error)
	{
		if (error == FR_EXIST)
		{
			PRINTF("Directory exists.\r\n");
		}
		else
		{
			PRINTF("Make directory failed.\r\n");
			return -1;
		}
	}
	#if 0
	PRINTF("\r\nCreate a lin csv......\r\n");
	error = f_open(&g_fileObject, _T("/logs/lin_log.csv"), (FA_WRITE | FA_READ | FA_CREATE_ALWAYS));
	if (error)
	{
		PRINTF("open lin file error.\r\n");
	}
	memset(g_bufferWrite, 0x00, sizeof(g_bufferWrite));
	strcpy(g_bufferWrite, "LIN-id,    length,    data0,    data1,    data2,    data3,    data4,    data5,    data6,    data7\r\n");


	if (f_lseek(&g_fileObject, f_size(&g_fileObject)))//0U))
	{
		PRINTF("Set file pointer position failed. \r\n");

	}
	//    error = f_write(&g_fileObject, g_bufferWrite, sizeof(g_bufferWrite), &bytesWritten);
	error = f_write(&g_fileObject, g_bufferWrite, strlen(g_bufferWrite), &bytesWritten);
	if ((error) || (bytesWritten != strlen(g_bufferWrite)))
	{
		PRINTF("Write file failed. \r\n");
	}

	if (f_close(&g_fileObject))
	{
		PRINTF("\r\nClose file failed.\r\n");
		return -1;
	}
	#endif

	PRINTF("\r\nCreate a canfd csv......\r\n");
	error = f_open(&canfd_fileObject, _T("/logs/canlog.csv"), (FA_WRITE | FA_READ | FA_CREATE_ALWAYS));
	if (error)
	{
		PRINTF("open canfd file error.\r\n");
	}
	memset(g_bufferWrite, 0x00, sizeof(g_bufferWrite));
	strcpy(g_bufferWrite, "BusType, CANFD/LIN-id,    length,    brs,    dword0    ,    dword1    ,    dword2    ,    dword3    ,    dword4    ,    dword5    ,    dword6    ,    dword7    ,\r\n");
	if (f_lseek(&canfd_fileObject, f_size(&canfd_fileObject)))
	{
		PRINTF("Set canfd file pointer position failed. \r\n");

	}

	error = f_write(&canfd_fileObject, g_bufferWrite, strlen(g_bufferWrite), &bytesWritten);
	if ((error) || (bytesWritten != strlen(g_bufferWrite)))
	{
		PRINTF("Write cafdfile failed. \r\n");
	}


//    if (f_close(&canfd_fileObject))
//    {
//        PRINTF("\r\nClose canfdfile failed.\r\n");
//        return -1;
//    }

}

void write_lin_file( uint8_t *writedata, uint8_t len )
{
	FRESULT error;
	UINT bytesWritten;
    error = f_write(&g_fileObject, writedata, len, &bytesWritten);
    if (error)
    {
        PRINTF("Write lin file failed. \r\n");
    }
}
//#define SD_MAX_RECORD_NUM   10
//uint32_t MCX_record_counter = 0;
void write_canfd_file( uint8_t *writedata, uint8_t len )
{
	FRESULT error;
	UINT bytesWritten;
	error = f_write(&canfd_fileObject, writedata, len, &bytesWritten);
	if (error)
	{
		PRINTF("Write canfd file failed. \r\n");
	}
}


void close_lin_file( void )
{
    if (f_close(&g_fileObject))
    {
        PRINTF("\r\nClose file failed.\r\n");

    }
}

void close_canfd_file( void )
{
    if (f_close(&canfd_fileObject))
    {
        PRINTF("\r\nClose cafdfile failed.\r\n");
    }
}
uint32_t FileOpenflg = false;
/*!
 * @brief Main function
 */
int main(void)
{
    /* Init board hardware. */
    /* attach FRO 12M to FLEXCOMM4 (debug console) */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* attach FRO 12M to FLEXCOMM2 */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);

    CLOCK_SetClkDiv(kCLOCK_DivFlexcom3Clk, 1u);
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM3);

    CLOCK_EnableClock(kCLOCK_Dma0);

    /* attach FRO HF to USDHC */
    CLOCK_SetClkDiv(kCLOCK_DivUSdhcClk, 1u);
    CLOCK_AttachClk(kFRO_HF_to_USDHC);

    BOARD_InitBootClocks();
    BOARD_InitBootPins();
    BOARD_InitDebugConsole();

#ifdef LIN_COM0
#ifdef LIN_MASTER
    GPIO_PortSet(BOARD_INITPINS_LIN1_M_GPIO, BOARD_INITPINS_LIN1_M_GPIO_PIN_MASK);
#else
    GPIO_PortClear(BOARD_INITPINS_LIN1_M_GPIO, BOARD_INITPINS_LIN1_M_GPIO_PIN_MASK);
#endif
#endif

#ifdef LIN_COM2
#ifdef LIN_MASTER
    GPIO_PortSet(BOARD_INITPINS_LIN0_M_GPIO, BOARD_INITPINS_LIN0_M_GPIO_PIN_MASK);
#else
    GPIO_PortClear(BOARD_INITPINS_LIN0_M_GPIO, BOARD_INITPINS_LIN0_M_GPIO_PIN_MASK);
#endif
#endif
    lpuart_config_t config;
	uint8_t PID;
    LPUART_GetDefaultConfig(&config);
    config.baudRate_Bps = 19200;
    config.enableTx     = true;
    config.enableRx     = true;

    LPUART_Init(DEMO_LIN, &config, DEMO_LIN_CLK_FREQ);
    uart_LIN_break( DEMO_LIN );


    PRINTF("\r\nStart CANFD Init\r\n");
    MCXN_flexcan_init();

    PRINTF("lvgl bare metal guider demo\r\n");
    DEMO_SetupTick();
#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    lv_port_pre_init();
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);
	GPIO_PinWrite(BOARD_INITLCDPINS_LCD_BL_GPIO, BOARD_INITLCDPINS_LCD_BL_PIN, 1);
    for (;;)
    {
/////////////////////////lvgl handle///////////////////////
        if(s_lvglTaskPending)
        {
			s_lvglTaskPending = false;
			lv_task_handler();
        }
/////////////////////////CANbus handle///////////////////////

        MCXN_flexcan_Test();
/////////////////////////Log handle///////////////////////
        if(CANFD_Startlog)
        {
        	CANFD_Startlog = false;
        	sd_savecsv_header();
        	FileOpenflg = true;
        }

        if(FileOpenflg)
        {
        	if(CANFD_Stoplog)
        	{
        		CANFD_Stoplog = false;
        		close_canfd_file();
        		PRINTF("\r\nClose file\r\n");
        		FileOpenflg = false;
        	}
        }
/////////////////////////LINbus handle///////////////////////
        if(state == SEND_DATA)
        {
			PID = LINCalcParity(0x2c);
			sendbuffer[2] = LINCheckSum( PID, sendbuffer, 2);
			LPUART_WriteBlocking(DEMO_LIN, sendbuffer, 3);
			sendbuffer[0]++;
			sendbuffer[1]++;
			recdatacnt=0;
			state = IDLE;
			EnableLinBreak;
        }
    }
}

static void DEMO_SetupTick(void)
{
    if (0 != SysTick_Config(SystemCoreClock / (LVGL_TICK_MS * 1000U)))
    {
        PRINTF("Tick initialization failed\r\n");
        while (1)
            ;
    }
}

void SysTick_Handler(void)
{
    s_tick++;
    lv_tick_inc(LVGL_TICK_MS);

    if ((s_tick % LVGL_TASK_PERIOD_TICK) == 0U)
    {
        s_lvglTaskPending = true;
    }

	if (g_systickCounter != 0U)
	{
	 g_systickCounter--;
	}
}

uint8_t LINCheckSum(uint8_t PID, uint8_t *buf, uint8_t lens)
{
    uint8_t i, ckm = 0;
    uint16_t chm1 = PID;//Enhanced
//    uint16_t chm1 = 0;//Classic
    for(i = 0; i < lens; i++)
    {
        chm1 += *(buf++);
    }
    ckm = chm1 / 256;
    ckm = ckm + chm1 % 256;
    ckm = 0xFF - ckm;

    return ckm;
}

uint8_t LINCalcParity(uint8_t id)
{
    uint8_t parity, p0,p1;
    parity=id;

    p0=((id & 0x01)^((id & 0x02) >> 1)^((id & 0x04) >> 2)^((id & 0x10) >> 4)) << 6;
    p1=(!((id & 0x02) >> 1)^((id & 0x08) >> 3)^((id & 0x10) >> 4)^((id & 0x20) >> 5)) << 7;
    parity|=(p0|p1);

    return parity;
}

#if LV_USE_LOG
static void print_cb(const char *buf)
{
    PRINTF("\r%s\n", buf);
}
#endif
