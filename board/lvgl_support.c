/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "lvgl_support.h"
#include "lvgl.h"
#if defined(SDK_OS_FREE_RTOS)
#include "FreeRTOS.h"
#include "semphr.h"
#endif

#include "board.h"
#include "fsl_gpio.h"

#include "fsl_lpi2c.h"
#include "fsl_port.h"
#include "fsl_lpspi_cmsis.h"
#include "pin_mux.h"
//#if BOARD_LCD_S035
//#include "fsl_st7796s.h"
//#include "fsl_gt911.h"
//#else
//#include "fsl_ssd1963.h"
//#include "fsl_ft5406_rt.h"
//#endif
#include "fsl_ili9341.h"
#include "fsl_gt911.h"
#include "cst816t.h"

#include "fsl_debug_console.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Port Me, Start. */
//#define BOARD_TOUCH_I2C           LPI2C1
//#define BOARD_TOUCH_I2C_IRQ       LPI2C3_IRQn
//#define BOARD_TOUCH_I2C_FREQ_FUNC LPI2C3_GetFreq
//#define BOARD_TOUCH_I2C_FREQ      CLOCK_GetLPFlexCommClkFreq(3u)//CLOCK_GetIpFreq(kCLOCK_Lpi2c1)
//#define DEMO_I2C_BAUDRATE            400000U

#define BOARD_LCD_SPI           Driver_SPI6
#define BOARD_LCD_SPI_BAUDRATE  75000000U
#define BOARD_LCD_SPI_IRQ       LPSPI6_IRQn
#define BOARD_LCD_SPI_FREQ_FUNC LPSPI6_GetFreq
#define BOARD_LCD_SPI_FREQ      CLOCK_GetLPFlexCommClkFreq(6u)//CLOCK_GetIpFreq(kCLOCK_Lpspi7)


/* Port Me. End */

#define DEMO_MS_TO_TICK(ms) ((ms * configTICK_RATE_HZ / 1000) + 1)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void DEMO_InitLcd(void);
static void DEMO_InitTouch(void);
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data);
static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile uint32_t spi_event;
static volatile bool spi_event_received;
#if defined(SDK_OS_FREE_RTOS)
static SemaphoreHandle_t s_transferDone;
#else
static volatile bool s_transferDone;
#endif
SDK_ALIGN(static uint8_t s_frameBuffer[1][LCD_VIRTUAL_BUF_SIZE * LCD_FB_BYTE_PER_PIXEL], 4);

void lv_port_pre_init(void)
{
}

uint32_t BOARD_LCD_SPI_FREQ_FUNC(void)
{
    return BOARD_LCD_SPI_FREQ;
}

//uint32_t BOARD_TOUCH_I2C_FREQ_FUNC(void)
//{
//    return BOARD_TOUCH_I2C_FREQ;
//}

static void SPI_MasterSignalEvent(uint32_t event)
{
#if defined(SDK_OS_FREE_RTOS)
    BaseType_t taskAwake = pdFALSE;

    xSemaphoreGiveFromISR(s_transferDone, &taskAwake);

    portYIELD_FROM_ISR(taskAwake);
#else
    s_transferDone = true;
#endif
}

static void SPI_WaitEvent(void)
{
#if defined(SDK_OS_FREE_RTOS)
    if (xSemaphoreTake(s_transferDone, portMAX_DELAY) != pdTRUE)
    {
        PRINTF("LCD SPI transfer error\r\n");
    }
#else
    while (false == s_transferDone)
    {
    }
    s_transferDone = false;
#endif
}

static void DEMO_SPI_LCD_WriteCmd(uint8_t Data)
{
    GPIO_PortClear(BOARD_INITLCDPINS_LCD_DS_GPIO, 1u << BOARD_INITLCDPINS_LCD_DS_PIN);
    BOARD_LCD_SPI.Send(&Data, 1);
    SPI_WaitEvent();
}

static void DEMO_SPI_LCD_WriteData(uint8_t Data)
{
    GPIO_PortSet(BOARD_INITLCDPINS_LCD_DS_GPIO, 1u << BOARD_INITLCDPINS_LCD_DS_PIN);
    BOARD_LCD_SPI.Send(&Data, 1);
    SPI_WaitEvent();
}

static void DEMO_SPI_LCD_WriteMultiData(const uint8_t *pData, int NumItems)
{
    GPIO_PortSet(BOARD_INITLCDPINS_LCD_DS_GPIO, 1u << BOARD_INITLCDPINS_LCD_DS_PIN);

    BOARD_LCD_SPI.Send(pData, NumItems);
    SPI_WaitEvent();
}

static void DEMO_InitLcd(void)
{
	GPIO_PinWrite(BOARD_INITLCDPINS_LCD_RST_GPIO, BOARD_INITLCDPINS_LCD_RST_PIN, 1);
	SDK_DelayAtLeastUs(100000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
	GPIO_PinWrite(BOARD_INITLCDPINS_LCD_RST_GPIO, BOARD_INITLCDPINS_LCD_RST_PIN, 0);
	SDK_DelayAtLeastUs(100000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
	GPIO_PinWrite(BOARD_INITLCDPINS_LCD_RST_GPIO, BOARD_INITLCDPINS_LCD_RST_PIN, 1);
	SDK_DelayAtLeastUs(100000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
#if defined(SDK_OS_FREE_RTOS)
    s_transferDone = xSemaphoreCreateBinary();
    if (NULL == s_transferDone)
    {
        PRINTF("Semaphore create failed\r\n");
        assert(0);
    }
#else
    s_transferDone = false;
#endif

#if defined(SDK_OS_FREE_RTOS)
    /* FreeRTOS kernel API is used in SPI ISR, so need to set proper IRQ priority. */
    NVIC_SetPriority(BOARD_LCD_SPI_IRQ, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
    // NVIC_SetPriority(BOARD_LCD_SPI_DMA_IRQ, configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);
#endif

    /* SPI master init */
    BOARD_LCD_SPI.Initialize(SPI_MasterSignalEvent);
    BOARD_LCD_SPI.PowerControl(ARM_POWER_FULL);
    BOARD_LCD_SPI.Control(ARM_SPI_MODE_MASTER, BOARD_LCD_SPI_BAUDRATE);
    FT9341_Init(DEMO_SPI_LCD_WriteData, DEMO_SPI_LCD_WriteCmd);
    /* Change to landscape view. */
//    DEMO_SPI_LCD_WriteCmd(0x2C);

}

void lv_port_disp_init(void)
{
    static lv_disp_draw_buf_t disp_buf;

    memset(s_frameBuffer, 0, sizeof(s_frameBuffer));
    lv_disp_draw_buf_init(&disp_buf, s_frameBuffer[0], NULL, LCD_VIRTUAL_BUF_SIZE);
//    lv_disp_draw_buf_init(&disp_buf, &s_frameBuffer[0], &s_frameBuffer[1], LCD_VIRTUAL_BUF_SIZE);

    /*-------------------------
     * Initialize your display
     * -----------------------*/
    DEMO_InitLcd();

    /*-----------------------------------
     * Register the display in LittlevGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv; /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);   /*Basic initialization*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = DEMO_FlushDisplay;

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

static void DEMO_FlushDisplay(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    lv_coord_t x1 = area->x1;
    lv_coord_t y1 = area->y1;
    lv_coord_t x2 = area->x2;
    lv_coord_t y2 = area->y2;

    y1 += 20;
	y2 += 20;

    uint8_t data[4] = {0};
    const uint8_t *pdata = (const uint8_t *)color_p;
    uint32_t send_size   = (x2 - x1 + 1) * (y2 - y1 + 1) * LCD_FB_BYTE_PER_PIXEL;

    /*Column addresses*/
    DEMO_SPI_LCD_WriteCmd(0x2A);
    data[0] = (x1 >> 8) & 0xFF;
    data[1] = x1 & 0xFF;
    data[2] = (x2 >> 8) & 0xFF;
    data[3] = x2 & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);

    /*Page addresses*/
    DEMO_SPI_LCD_WriteCmd(0x2B);
    data[0] = (y1 >> 8) & 0xFF;
    data[1] = y1 & 0xFF;
    data[2] = (y2 >> 8) & 0xFF;
    data[3] = y2 & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);

    /*Memory write*/
    DEMO_SPI_LCD_WriteCmd(0x2C);
    DEMO_SPI_LCD_WriteMultiData(pdata, send_size);

    lv_disp_flush_ready(disp_drv);
}

/******************************************************************************
function :  Clear screen
parameter:
******************************************************************************/
void LCD_screen_Clear( void )
{
    uint32_t i,j;
    uint8_t data[4] = {0};

//    LCD_1IN69_SetWindows(0, 0, LCD_1IN69.WIDTH, LCD_1IN69.HEIGHT);
    /*Column addresses*/
    DEMO_SPI_LCD_WriteCmd(0x2A);
    data[0] = 0x00;
    data[1] = 0x00;
    data[2] = (LCD_WIDTH >> 8) & 0xFF;
    data[3] = LCD_WIDTH & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);
    /*Page addresses*/
    DEMO_SPI_LCD_WriteCmd(0x2B);
    data[0] = 0x00;
    data[1] = 20;
    data[2] = ((LCD_HEIGHT+20) >> 8) & 0xFF;
    data[3] = (LCD_HEIGHT+20) & 0xFF;
    DEMO_SPI_LCD_WriteMultiData(data, 4);

    DEMO_SPI_LCD_WriteCmd(0x2C);
//    DEV_Digital_Write(DEV_DC_PIN, 1);
    data[0] = 0xFF;
    data[1] = 0xFF;
    for(i = 0; i < LCD_WIDTH; i++) {
        for(j = 0; j < LCD_HEIGHT; j++) {
//            DEV_SPI_WRITE((Color>>8)&0xff);
//            DEV_SPI_WRITE(Color);
        	DEMO_SPI_LCD_WriteMultiData(data, 2);
        }
     }
}

void lv_port_indev_init(void)
{
    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad */
    DEMO_InitTouch();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type    = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = DEMO_ReadTouch;
    lv_indev_drv_register(&indev_drv);
}

static void I2C_MasterSignalEvent(uint32_t event)
{
    /* Notify touch driver about status of the IO operation */
    //FT6X06_EventHandler(&touch_handle, event);
}

/*Initialize your touchpad*/
static void DEMO_InitTouch(void)
{
	cst816t_init();
}

/* Will be called by the library to read the touchpad */
static void DEMO_ReadTouch(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    uint8_t touch_points_num = 0;
    int16_t x = 0;
    int16_t y = 0;

    cst816t_read_pos(&touch_points_num,&x,&y);

#if CONFIG_LV_CST816T_INVERT_X
    x = LV_HOR_RES_MAX - x;
#endif
#if CONFIG_LV_CST816T_INVERT_Y
    y = LV_VER_RES_MAX - y;
#endif
#if CONFIG_LV_CST816T_SWAPXY
    int16_t swap_buf = x;
    x = y;
    y = swap_buf;
#endif

    data->point.x = x;
    data->point.y = y;
    if (touch_points_num > 0){
        data->state = LV_INDEV_STATE_PR;
    }
    else{
        data->state = LV_INDEV_STATE_REL;
    }
    // ESP_LOGI(TAG, "X=%u Y=%u", data->point.x, data->point.y);
    // ESP_LOGV(TAG, "X=%u Y=%u", data->point.x, data->point.y);

}



