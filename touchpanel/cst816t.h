#ifndef __CST816T_H
#define __CST816T_H

#include <stdint.h>
#include <stdbool.h>
#include "fsl_common.h"
#include "lvgl_support.h"
//#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bool inited;
    char product_id[1];
    uint16_t max_x_coord;
    uint16_t max_y_coord;
    uint8_t i2c_dev_addr;
} cst816t_status_t;


#define CST816T_ADDR 			 	0x15
#define CST816T_I2C_SLAVE_ADDR   	0x15
#define CST816T_REG_ADDR_SIZE 		1
#define CST816T_REG_ID   			0xA7

#define CST816T_ADDRESS 0x15
#define REG_GESTURE_ID 0x01
#define REG_FINGER_NUM 0x02
#define REG_XPOS_H 0x03
#define REG_XPOS_L 0x04
#define REG_YPOS_H 0x05
#define REG_YPOS_L 0x06
#define REG_CHIP_ID 0xA7
#define REG_PROJ_ID 0xA8
#define REG_FW_VERSION 0xA9
#define REG_FACTORY_ID 0xAA
#define REG_SLEEP_MODE 0xE5
#define REG_IRQ_CTL 0xFA
#define REG_LONG_PRESS_TICK 0xEB
#define REG_MOTION_MASK 0xEC
#define REG_DIS_AUTOSLEEP 0xFE

#define MOTION_MASK_CONTINUOUS_LEFT_RIGHT 0b100
#define MOTION_MASK_CONTINUOUS_UP_DOWN 0b010
#define MOTION_MASK_DOUBLE_CLICK 0b001



void cst816t_init( void );
status_t cst816t_read_pos(uint8_t *touch_points_num, uint16_t *x, uint16_t *y);
//bool cst816t_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

#endif

#ifdef __cplusplus
}
// #endif
#endif /* __CST816T_H */
