/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen, LV_OBJ_FLAG_CLICKABLE);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_tabview_1
    ui->screen_tabview_1 = lv_tabview_create(ui->screen, LV_DIR_TOP, 50);
    lv_obj_set_pos(ui->screen_tabview_1, 0, 0);
    lv_obj_set_size(ui->screen_tabview_1, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_tabview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_tabview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_tabview_1, lv_color_hex(0xeaeff3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_tabview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_tabview_1, lv_color_hex(0x4d4d4d), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_tabview_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_tabview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_tabview_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_tabview_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_tabview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_tabview_1_extra_btnm_main_default
    static lv_style_t style_screen_tabview_1_extra_btnm_main_default;
    ui_init_style(&style_screen_tabview_1_extra_btnm_main_default);

    lv_style_set_bg_opa(&style_screen_tabview_1_extra_btnm_main_default, 255);
    lv_style_set_bg_color(&style_screen_tabview_1_extra_btnm_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_tabview_1_extra_btnm_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_screen_tabview_1_extra_btnm_main_default, 0);
    lv_style_set_radius(&style_screen_tabview_1_extra_btnm_main_default, 0);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_tabview_1), &style_screen_tabview_1_extra_btnm_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_tabview_1_extra_btnm_items_default
    static lv_style_t style_screen_tabview_1_extra_btnm_items_default;
    ui_init_style(&style_screen_tabview_1_extra_btnm_items_default);

    lv_style_set_text_color(&style_screen_tabview_1_extra_btnm_items_default, lv_color_hex(0x4d4d4d));
    lv_style_set_text_font(&style_screen_tabview_1_extra_btnm_items_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_tabview_1_extra_btnm_items_default, 255);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_tabview_1), &style_screen_tabview_1_extra_btnm_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_tabview_1_extra_btnm_items_checked
    static lv_style_t style_screen_tabview_1_extra_btnm_items_checked;
    ui_init_style(&style_screen_tabview_1_extra_btnm_items_checked);

    lv_style_set_text_color(&style_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_text_font(&style_screen_tabview_1_extra_btnm_items_checked, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_width(&style_screen_tabview_1_extra_btnm_items_checked, 4);
    lv_style_set_border_opa(&style_screen_tabview_1_extra_btnm_items_checked, 255);
    lv_style_set_border_color(&style_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_border_side(&style_screen_tabview_1_extra_btnm_items_checked, LV_BORDER_SIDE_BOTTOM);
    lv_style_set_radius(&style_screen_tabview_1_extra_btnm_items_checked, 0);
    lv_style_set_bg_opa(&style_screen_tabview_1_extra_btnm_items_checked, 60);
    lv_style_set_bg_color(&style_screen_tabview_1_extra_btnm_items_checked, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_tabview_1_extra_btnm_items_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_tabview_get_tab_btns(ui->screen_tabview_1), &style_screen_tabview_1_extra_btnm_items_checked, LV_PART_ITEMS|LV_STATE_CHECKED);

    //Write codes LIN BUS
    ui->screen_tabview_1_tab_1 = lv_tabview_add_tab(ui->screen_tabview_1,"LIN BUS");
    lv_obj_t * screen_tabview_1_tab_1_label = lv_label_create(ui->screen_tabview_1_tab_1);
    lv_label_set_text(screen_tabview_1_tab_1_label, "");

    //Write codes screen_btn_start_lin
    ui->screen_btn_start_lin = lv_btn_create(ui->screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->screen_btn_start_lin, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_btn_start_lin_label = lv_label_create(ui->screen_btn_start_lin);
    lv_label_set_text(ui->screen_btn_start_lin_label, "Start");
    lv_label_set_long_mode(ui->screen_btn_start_lin_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_start_lin_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_start_lin, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_start_lin_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_btn_start_lin, 40, 95);
    lv_obj_set_size(ui->screen_btn_start_lin, 120, 45);
    lv_obj_add_flag(ui->screen_btn_start_lin, LV_OBJ_FLAG_CLICKABLE);

    //Write style for screen_btn_start_lin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_start_lin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_start_lin, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_start_lin, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_start_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_start_lin, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_start_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_start_lin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_start_lin, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_start_lin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_start_lin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ddlist_slave_bitrate
    ui->screen_ddlist_slave_bitrate = lv_dropdown_create(ui->screen_tabview_1_tab_1);
    lv_dropdown_set_options(ui->screen_ddlist_slave_bitrate, "19200\n10400\n9600\n2400");
    lv_dropdown_set_symbol(ui->screen_ddlist_slave_bitrate, NULL);
    lv_obj_set_pos(ui->screen_ddlist_slave_bitrate, 51, 19);
    lv_obj_set_size(ui->screen_ddlist_slave_bitrate, 84, 28);

    //Write style for screen_ddlist_slave_bitrate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ddlist_slave_bitrate, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ddlist_slave_bitrate, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ddlist_slave_bitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ddlist_slave_bitrate, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ddlist_slave_bitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ddlist_slave_bitrate, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ddlist_slave_bitrate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ddlist_slave_bitrate, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ddlist_slave_bitrate, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ddlist_slave_bitrate, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ddlist_slave_bitrate, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ddlist_slave_bitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ddlist_slave_bitrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_slave_bitrate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ddlist_slave_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_ddlist_slave_bitrate_extra_list_selected_checked
    static lv_style_t style_screen_ddlist_slave_bitrate_extra_list_selected_checked;
    ui_init_style(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_slave_bitrate_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_slave_bitrate), &style_screen_ddlist_slave_bitrate_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_slave_bitrate_extra_list_main_default
    static lv_style_t style_screen_ddlist_slave_bitrate_extra_list_main_default;
    ui_init_style(&style_screen_ddlist_slave_bitrate_extra_list_main_default);

    lv_style_set_max_height(&style_screen_ddlist_slave_bitrate_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_ddlist_slave_bitrate_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_ddlist_slave_bitrate_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_ddlist_slave_bitrate_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_ddlist_slave_bitrate_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_ddlist_slave_bitrate_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_ddlist_slave_bitrate_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_slave_bitrate_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_slave_bitrate_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_slave_bitrate_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_slave_bitrate_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_slave_bitrate_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_slave_bitrate), &style_screen_ddlist_slave_bitrate_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default
    static lv_style_t style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default;
    ui_init_style(&style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_slave_bitrate), &style_screen_ddlist_slave_bitrate_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_btn_stop_lin
    ui->screen_btn_stop_lin = lv_btn_create(ui->screen_tabview_1_tab_1);
    lv_obj_add_flag(ui->screen_btn_stop_lin, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_btn_stop_lin_label = lv_label_create(ui->screen_btn_stop_lin);
    lv_label_set_text(ui->screen_btn_stop_lin_label, "Stop");
    lv_label_set_long_mode(ui->screen_btn_stop_lin_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_stop_lin_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_stop_lin, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_stop_lin_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_btn_stop_lin, 40, 150);
    lv_obj_set_size(ui->screen_btn_stop_lin, 120, 45);

    //Write style for screen_btn_stop_lin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_stop_lin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_stop_lin, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_stop_lin, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_stop_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_stop_lin, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_stop_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_stop_lin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_stop_lin, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_stop_lin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_stop_lin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_lin_bitrate
    ui->screen_label_lin_bitrate = lv_label_create(ui->screen_tabview_1_tab_1);
    lv_label_set_text(ui->screen_label_lin_bitrate, "Slave Bit rate");
    lv_label_set_long_mode(ui->screen_label_lin_bitrate, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_lin_bitrate, 34, -6);
    lv_obj_set_size(ui->screen_label_lin_bitrate, 120, 17);

    //Write style for screen_label_lin_bitrate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_lin_bitrate, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_lin_bitrate, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_lin_bitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_lin_bitrate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_lin_bitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_lin
    ui->screen_label_lin = lv_label_create(ui->screen_tabview_1_tab_1);
    lv_label_set_text(ui->screen_label_lin, "");
    lv_label_set_long_mode(ui->screen_label_lin, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_lin, 39, 60);
    lv_obj_set_size(ui->screen_label_lin, 124, 21);

    //Write style for screen_label_lin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_lin, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_lin, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_lin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_lin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_lin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes CANFD
    ui->screen_tabview_1_tab_2 = lv_tabview_add_tab(ui->screen_tabview_1,"CANFD");
    lv_obj_t * screen_tabview_1_tab_2_label = lv_label_create(ui->screen_tabview_1_tab_2);
    lv_label_set_text(screen_tabview_1_tab_2_label, "");

    //Write codes screen_btn_start_canfd
    ui->screen_btn_start_canfd = lv_btn_create(ui->screen_tabview_1_tab_2);
    lv_obj_add_flag(ui->screen_btn_start_canfd, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_btn_start_canfd_label = lv_label_create(ui->screen_btn_start_canfd);
    lv_label_set_text(ui->screen_btn_start_canfd_label, "Start");
    lv_label_set_long_mode(ui->screen_btn_start_canfd_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_start_canfd_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_start_canfd, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_start_canfd_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_btn_start_canfd, 10, 134);
    lv_obj_set_size(ui->screen_btn_start_canfd, 84, 35);

    //Write style for screen_btn_start_canfd, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_start_canfd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_start_canfd, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_start_canfd, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_start_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_start_canfd, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_start_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_start_canfd, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_start_canfd, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_start_canfd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_start_canfd, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ddlist_normalbitrate
    ui->screen_ddlist_normalbitrate = lv_dropdown_create(ui->screen_tabview_1_tab_2);
    lv_dropdown_set_options(ui->screen_ddlist_normalbitrate, "500K\n250K\n1000K\n125K");
    lv_dropdown_set_symbol(ui->screen_ddlist_normalbitrate, NULL);
    lv_obj_set_pos(ui->screen_ddlist_normalbitrate, 3, 44);
    lv_obj_set_size(ui->screen_ddlist_normalbitrate, 81, 29);

    //Write style for screen_ddlist_normalbitrate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ddlist_normalbitrate, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ddlist_normalbitrate, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ddlist_normalbitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ddlist_normalbitrate, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ddlist_normalbitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ddlist_normalbitrate, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ddlist_normalbitrate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ddlist_normalbitrate, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ddlist_normalbitrate, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ddlist_normalbitrate, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ddlist_normalbitrate, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ddlist_normalbitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ddlist_normalbitrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_normalbitrate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ddlist_normalbitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_ddlist_normalbitrate_extra_list_selected_checked
    static lv_style_t style_screen_ddlist_normalbitrate_extra_list_selected_checked;
    ui_init_style(&style_screen_ddlist_normalbitrate_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_normalbitrate_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_normalbitrate), &style_screen_ddlist_normalbitrate_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_normalbitrate_extra_list_main_default
    static lv_style_t style_screen_ddlist_normalbitrate_extra_list_main_default;
    ui_init_style(&style_screen_ddlist_normalbitrate_extra_list_main_default);

    lv_style_set_max_height(&style_screen_ddlist_normalbitrate_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_ddlist_normalbitrate_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_ddlist_normalbitrate_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_ddlist_normalbitrate_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_ddlist_normalbitrate_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_ddlist_normalbitrate_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_ddlist_normalbitrate_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_normalbitrate_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_normalbitrate_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_normalbitrate_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_normalbitrate_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_normalbitrate_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_normalbitrate), &style_screen_ddlist_normalbitrate_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_normalbitrate_extra_list_scrollbar_default
    static lv_style_t style_screen_ddlist_normalbitrate_extra_list_scrollbar_default;
    ui_init_style(&style_screen_ddlist_normalbitrate_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_ddlist_normalbitrate_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_normalbitrate_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_normalbitrate_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_normalbitrate_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_normalbitrate), &style_screen_ddlist_normalbitrate_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_ddlist_databitrate
    ui->screen_ddlist_databitrate = lv_dropdown_create(ui->screen_tabview_1_tab_2);
    lv_dropdown_set_options(ui->screen_ddlist_databitrate, "2M\n4M\n5M\n8M\n10M");
    lv_dropdown_set_symbol(ui->screen_ddlist_databitrate, NULL);
    lv_obj_set_pos(ui->screen_ddlist_databitrate, 117, 44);
    lv_obj_set_size(ui->screen_ddlist_databitrate, 81, 29);

    //Write style for screen_ddlist_databitrate, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ddlist_databitrate, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ddlist_databitrate, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ddlist_databitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ddlist_databitrate, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ddlist_databitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ddlist_databitrate, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ddlist_databitrate, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ddlist_databitrate, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ddlist_databitrate, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ddlist_databitrate, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ddlist_databitrate, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ddlist_databitrate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ddlist_databitrate, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ddlist_databitrate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ddlist_databitrate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_screen_ddlist_databitrate_extra_list_selected_checked
    static lv_style_t style_screen_ddlist_databitrate_extra_list_selected_checked;
    ui_init_style(&style_screen_ddlist_databitrate_extra_list_selected_checked);

    lv_style_set_border_width(&style_screen_ddlist_databitrate_extra_list_selected_checked, 1);
    lv_style_set_border_opa(&style_screen_ddlist_databitrate_extra_list_selected_checked, 255);
    lv_style_set_border_color(&style_screen_ddlist_databitrate_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_databitrate_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_databitrate_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_databitrate_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_screen_ddlist_databitrate_extra_list_selected_checked, lv_color_hex(0x00a1b5));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_databitrate_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_databitrate), &style_screen_ddlist_databitrate_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_databitrate_extra_list_main_default
    static lv_style_t style_screen_ddlist_databitrate_extra_list_main_default;
    ui_init_style(&style_screen_ddlist_databitrate_extra_list_main_default);

    lv_style_set_max_height(&style_screen_ddlist_databitrate_extra_list_main_default, 90);
    lv_style_set_text_color(&style_screen_ddlist_databitrate_extra_list_main_default, lv_color_hex(0x0D3055));
    lv_style_set_text_font(&style_screen_ddlist_databitrate_extra_list_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_ddlist_databitrate_extra_list_main_default, 255);
    lv_style_set_border_width(&style_screen_ddlist_databitrate_extra_list_main_default, 1);
    lv_style_set_border_opa(&style_screen_ddlist_databitrate_extra_list_main_default, 255);
    lv_style_set_border_color(&style_screen_ddlist_databitrate_extra_list_main_default, lv_color_hex(0xe1e6ee));
    lv_style_set_border_side(&style_screen_ddlist_databitrate_extra_list_main_default, LV_BORDER_SIDE_FULL);
    lv_style_set_radius(&style_screen_ddlist_databitrate_extra_list_main_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_databitrate_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_databitrate_extra_list_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_databitrate_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_databitrate), &style_screen_ddlist_databitrate_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_ddlist_databitrate_extra_list_scrollbar_default
    static lv_style_t style_screen_ddlist_databitrate_extra_list_scrollbar_default;
    ui_init_style(&style_screen_ddlist_databitrate_extra_list_scrollbar_default);

    lv_style_set_radius(&style_screen_ddlist_databitrate_extra_list_scrollbar_default, 3);
    lv_style_set_bg_opa(&style_screen_ddlist_databitrate_extra_list_scrollbar_default, 255);
    lv_style_set_bg_color(&style_screen_ddlist_databitrate_extra_list_scrollbar_default, lv_color_hex(0x00ff00));
    lv_style_set_bg_grad_dir(&style_screen_ddlist_databitrate_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->screen_ddlist_databitrate), &style_screen_ddlist_databitrate_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_btn_stop_canfd
    ui->screen_btn_stop_canfd = lv_btn_create(ui->screen_tabview_1_tab_2);
    lv_obj_add_flag(ui->screen_btn_stop_canfd, LV_OBJ_FLAG_CHECKABLE);
    ui->screen_btn_stop_canfd_label = lv_label_create(ui->screen_btn_stop_canfd);
    lv_label_set_text(ui->screen_btn_stop_canfd_label, "Stop");
    lv_label_set_long_mode(ui->screen_btn_stop_canfd_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_stop_canfd_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_stop_canfd, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_stop_canfd_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_btn_stop_canfd, 110, 134);
    lv_obj_set_size(ui->screen_btn_stop_canfd, 84, 35);

    //Write style for screen_btn_stop_canfd, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_stop_canfd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_stop_canfd, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_stop_canfd, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_stop_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_stop_canfd, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_stop_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_stop_canfd, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_stop_canfd, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_stop_canfd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_stop_canfd, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_normal_canfd
    ui->screen_label_normal_canfd = lv_label_create(ui->screen_tabview_1_tab_2);
    lv_label_set_text(ui->screen_label_normal_canfd, "Normal Bitrate");
    lv_label_set_long_mode(ui->screen_label_normal_canfd, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_normal_canfd, -1, 18);
    lv_obj_set_size(ui->screen_label_normal_canfd, 103, 18);

    //Write style for screen_label_normal_canfd, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_normal_canfd, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_normal_canfd, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_normal_canfd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_normal_canfd, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_normal_canfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_datacanfd
    ui->screen_label_datacanfd = lv_label_create(ui->screen_tabview_1_tab_2);
    lv_label_set_text(ui->screen_label_datacanfd, "Data Bitrate");
    lv_label_set_long_mode(ui->screen_label_datacanfd, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_datacanfd, 106, 18);
    lv_obj_set_size(ui->screen_label_datacanfd, 98, 18);

    //Write style for screen_label_datacanfd, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_datacanfd, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_datacanfd, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_datacanfd, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_datacanfd, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_datacanfd, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_canfd_status
    ui->screen_label_canfd_status = lv_label_create(ui->screen_tabview_1_tab_2);
    lv_label_set_text(ui->screen_label_canfd_status, "");
    lv_label_set_long_mode(ui->screen_label_canfd_status, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_canfd_status, 32, 92);
    lv_obj_set_size(ui->screen_label_canfd_status, 140, 21);

    //Write style for screen_label_canfd_status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_canfd_status, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_canfd_status, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_canfd_status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_canfd_status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_canfd_status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_sw_brs
    ui->screen_sw_brs = lv_switch_create(ui->screen_tabview_1_tab_2);
    lv_obj_set_pos(ui->screen_sw_brs, 84, 177);
    lv_obj_set_size(ui->screen_sw_brs, 40, 22);

    //Write style for screen_sw_brs, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_brs, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_brs, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_brs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_brs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_brs, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_sw_brs, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_sw_brs, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->screen_sw_brs, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui->screen_sw_brs, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_brs, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->screen_sw_brs, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->screen_sw_brs, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->screen_sw_brs, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for screen_sw_brs, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->screen_sw_brs, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->screen_sw_brs, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_brs, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->screen_sw_brs, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for screen_sw_brs, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_sw_brs, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_sw_brs, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_sw_brs, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_sw_brs, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_sw_brs, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_label_BRS
    ui->screen_label_BRS = lv_label_create(ui->screen_tabview_1_tab_2);
    lv_label_set_text(ui->screen_label_BRS, "BRS:");
    lv_label_set_long_mode(ui->screen_label_BRS, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_BRS, 28, 181);
    lv_obj_set_size(ui->screen_label_BRS, 50, 19);

    //Write style for screen_label_BRS, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_BRS, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_BRS, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_BRS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_BRS, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_BRS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
