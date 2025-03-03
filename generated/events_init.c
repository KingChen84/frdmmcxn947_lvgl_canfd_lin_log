/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void screen_btn_start_lin_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	LIN_Startlog = true;
    	PRINTF("\r\nLIN_Startlog = true\r\n");
        lv_label_set_text(guider_ui.screen_label_lin, "Start LIN log");
        break;
    }
    default:
        break;
    }
}

static void screen_ddlist_slave_bitrate_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCROLL:
    {
        uint16_t id = lv_dropdown_get_selected(guider_ui.screen_ddlist_slave_bitrate);
        break;
    }
    default:
        break;
    }
}

static void screen_btn_stop_lin_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	LIN_Startlog = false;
    	PRINTF("\r\nLIN_Startlog = false\r\n");
        lv_label_set_text(guider_ui.screen_label_lin, "Stop LIN log");
        break;
    }
    default:
        break;
    }
}

static void screen_btn_start_canfd_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	CANFD_Startlog = true;
    	PRINTF("\r\nCANFD_Startlog = true\r\n");
        lv_label_set_text(guider_ui.screen_label_canfd_status, "Start CAN log...");
        break;
    }
    default:
        break;
    }
}

static void screen_btn_stop_canfd_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	CANFD_Startlog = false;
    	CANFD_Stoplog = true;
    	PRINTF("\r\nCAN_Startlog = false\r\n");
        lv_label_set_text(guider_ui.screen_label_canfd_status, "Stop CAN log");
        break;
    }
    default:
        break;
    }
}

static void screen_sw_brs_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        	CAN_brsflg = status;
        	PRINTF("\r\nCAN_brsflg = %d\r\n",CAN_brsflg);
        break;
    }
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;

        break;
    }
    default:
        break;
    }
}

void events_init_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_btn_start_lin, screen_btn_start_lin_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_ddlist_slave_bitrate, screen_ddlist_slave_bitrate_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_stop_lin, screen_btn_stop_lin_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_start_canfd, screen_btn_start_canfd_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_btn_stop_canfd, screen_btn_stop_canfd_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_sw_brs, screen_sw_brs_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
