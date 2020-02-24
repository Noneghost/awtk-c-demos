﻿/**
 * File:   basic.c
 * Author: AWTK Develop Team
 * Brief:  demo widget clone bench mark
 *
 * Copyright (c) 2018 - 2020  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2019-11-108 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "awtk.h"

static ret_t on_click(void* ctx, event_t* e) {
  uint32_t i = 0;
  uint32_t n = 100 * 10000;
  widget_t* view = WIDGET(ctx);
  widget_t* item = widget_get_child(view, 0);
  uint64_t start = time_now_ms();
  uint64_t cost = time_now_ms();

  for(i = 0; i < n; i++) {
    widget_clone(item, view);
  }
 
  cost = time_now_ms() - start;
  log_debug("clone %u cost %llu\n", n, cost);

  return RET_OK;
}

ret_t application_init() {
  widget_t* win = window_open("list_view_m");
  widget_t* view = widget_lookup_by_type(win, WIDGET_TYPE_SCROLL_VIEW, TRUE);
  widget_t* button = widget_lookup(win, "close", TRUE);

  widget_set_text_utf8(button, "Clone");
  widget_on(button, EVT_CLICK, on_click, view);

  return RET_OK;
}

ret_t application_exit() {
  log_debug("application_exit\n");
  return RET_OK;
}

#include "awtk_main.inc"
