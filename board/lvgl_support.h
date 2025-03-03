/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LVGL_SUPPORT_H
#define LVGL_SUPPORT_H

#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#ifndef BOARD_USE_FLEXIO_SMARTDMA
#define BOARD_USE_FLEXIO_SMARTDMA 1
#endif

//#ifndef BOARD_LCD_S035
//#define BOARD_LCD_S035 1
//#endif

//#if BOARD_LCD_S035
//#define LCD_WIDTH  480
//#define LCD_HEIGHT 320
//#else
//#define LCD_WIDTH  800
//#define LCD_HEIGHT 480
//#endif
#define LCD_WIDTH  240
#define LCD_HEIGHT 280

#define LCD_FB_BYTE_PER_PIXEL 2
/* The virtual buffer for DBI panel, it should be ~1/10 screen size. */
#define LCD_VIRTUAL_BUF_HEIGHT (LCD_HEIGHT / 10)
#define LCD_VIRTUAL_BUF_SIZE   (LCD_WIDTH * LCD_VIRTUAL_BUF_HEIGHT)

/* LCD panel. */
#define BOARD_LCD_RST_GPIO GPIO4
#define BOARD_LCD_RST_PIN  7
#define BOARD_LCD_TE_GPIO  GPIO4
#define BOARD_LCD_TE_PIN   23
#define BOARD_LCD_CS_GPIO  GPIO4
#define BOARD_LCD_CS_PIN   14
#define BOARD_LCD_RS_GPIO  GPIO0
#define BOARD_LCD_RS_PIN   24
#define BOARD_LCD_INT_PORT PORT0
#define BOARD_LCD_INT_GPIO GPIO0
#define BOARD_LCD_INT_PIN  23


/* Macros for the touch touch controller. */
#define BOARD_TOUCH_I2C            		LPI2C3
#define BOARD_TOUCH_I2C_CLOCK_FREQ 		CLOCK_GetLPFlexCommClkFreq(3u)
#define BOARD_TOUCH_I2C_BAUDRATE   		100000U
/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void lv_port_pre_init(void);
void lv_port_disp_init(void);
void lv_port_indev_init(void);

#if defined(__cplusplus)
}
#endif

#endif /*LVGL_SUPPORT_H */
