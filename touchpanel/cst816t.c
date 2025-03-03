#include "cst816t.h"
#include "board.h"


static cst816t_status_t cst816t_status;
status_t cst816t_read_len(uint16_t reg_addr,uint8_t *data,uint8_t len)
{
	status_t ret_status;
	ret_status = BOARD_LPI2C_Receive(BOARD_TOUCH_I2C, CST816T_I2C_SLAVE_ADDR, reg_addr, CST816T_REG_ADDR_SIZE, data, len);
	return ret_status;
}


status_t cst816t_chipId(void)
{
    return 0;
}
static status_t  cst816t_get_touch_points_num(uint8_t *touch_points_num)
{
    uint8_t res=0;
    res = cst816t_read_len(0x02, touch_points_num,1);
    return res;
}

status_t cst816t_read_pos(uint8_t *touch_points_num, uint16_t *x, uint16_t *y)
{
    uint8_t data[4];

    cst816t_get_touch_points_num(touch_points_num);
    if (0 == *touch_points_num)
    {
        *x=0;
        *y=0;
        return 1;
    }else
    {
        cst816t_read_len(0x03, data,4);

        *x = ((data[0] & 0x0f) << 8) | data[1];
        *y = ((data[2] & 0x0f) << 8) | data[3];
    }

    return 0;
}




status_t cst816t_i2c_read(uint8_t slave_addr, uint16_t register_addr, uint8_t *data_buf, uint8_t len)
{
	status_t ret_status;
	ret_status = BOARD_LPI2C_Receive(BOARD_TOUCH_I2C, CST816T_I2C_SLAVE_ADDR, register_addr, CST816T_REG_ADDR_SIZE, data_buf, len);
	return ret_status;
}

status_t cst816t_i2c_write8(uint8_t slave_addr, uint16_t register_addr, uint8_t data) {
    uint8_t buffer = data;
}



void cst816t_init( void )
{
	uint8_t data_buf[10] = {0};
	status_t ret;
	uint32_t ReqClock = 0;
	ReqClock = BOARD_TOUCH_I2C_CLOCK_FREQ;
	BOARD_LPI2C_Init( BOARD_TOUCH_I2C, BOARD_TOUCH_I2C_CLOCK_FREQ);
//	ret = BOARD_LPI2C_Send(BOARD_TOUCH_I2C, CST816T_I2C_SLAVE_ADDR, 0x15, 1, &data_buf, 1);
	ret = BOARD_LPI2C_Receive(BOARD_TOUCH_I2C, CST816T_I2C_SLAVE_ADDR, REG_CHIP_ID, 1, &data_buf, 1);
	ret = 1;
}

/*
bool cst816t_read(lv_indev_drv_t *drv, lv_indev_data_t *data) {
    
    uint8_t touch_points_num = 0;
    uint16_t x = 0;
    uint16_t y = 0;

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
    return false;
}
*/
