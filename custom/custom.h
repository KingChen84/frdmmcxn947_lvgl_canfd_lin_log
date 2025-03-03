/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _CUSTOM_H_
#define _CUSTOM_H_

#include "gui_guider.h"
extern uint32_t LIN_Startlog;
extern uint32_t CANFD_Startlog;
extern uint32_t CANFD_Stoplog;
extern uint32_t CAN_brsflg;
/* User code. */
void custom_init(lv_ui *ui);

#endif
