/* --------------------------------------------------------------------------
 *
 * Defination for OLED (SSD1306) I2C driver
 * Copyright (C) 2018, Anthony Lee, All Rights Reserved
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * File: oled_ssd1306_ioctl.h
 * Description:
 *
 * --------------------------------------------------------------------------*/

#ifndef __OLED_SSD1306_IOCTL_H__
#define __OLED_SSD1306_IOCTL_H__

enum {
	_OLED_SSD1306_TIMESTAMP	= 0,
	_OLED_SSD1306_CLEAR,
	_OLED_SSD1306_SHOW,
	_OLED_SSD1306_UPDATE,
	_OLED_SSD1306_POWER,
	_OLED_SSD1306_STRING_WIDTH,
	_OLED_SSD1306_BUFFER,
	_OLED_SSD1306_INVERT,
	_OLED_SSD1306_SET_CLIPPING,
	_OLED_SSD1306_SET_OFF_TIMEOUT,
	_OLED_SSD1306_GET_PROP,
};

typedef struct {
	int last_action;
	uint64_t ts;
} _oled_ssd1306_ts_t;

typedef struct {
	uint8_t x;
	uint8_t y;
	uint8_t w;
	uint8_t h;
	uint8_t patterns[8];
	uint64_t ts;
} _oled_ssd1306_clear_t;

typedef struct {
	int16_t x;
	int16_t y;
	uint8_t size;
	uint8_t erase_mode;
	char str[128];
	uint8_t reserved[6];
	uint64_t ts;
} _oled_ssd1306_show_t;

typedef struct {
	uint16_t w;
	uint16_t h;
	char str[128];
	uint8_t reserved[5];
	uint8_t size;
} _oled_ssd1306_string_width_t;

typedef struct {
	int state; // 0 and 1 for controling, others for accessing
	uint64_t ts;
} _oled_ssd1306_power_t;

typedef struct {
	int action; // 0: recopy  1: flush
	uint64_t ts;
} _oled_ssd1306_buffer_t;

typedef struct {
	uint8_t x;
	uint8_t y;
	uint8_t w;
	uint8_t h;
	uint64_t ts;
} _oled_ssd1306_invert_t;

typedef struct {
	uint8_t x;
	uint8_t y;
	uint8_t w;
	uint8_t h;
	uint64_t ts;
} _oled_ssd1306_set_clipping_t;

typedef struct {
	uint16_t w;
	uint16_t h;
} _oled_ssd1306_prop_t;

#define OLED_SSD1306_IOC_BASE			0x3c

#define OLED_SSD1306_IOC_TIMESTAMP		_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_TIMESTAMP, _oled_ssd1306_ts_t)
#define OLED_SSD1306_IOC_CLEAR			_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_CLEAR, _oled_ssd1306_clear_t)
#define OLED_SSD1306_IOC_SHOW			_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_SHOW, _oled_ssd1306_show_t)
#define OLED_SSD1306_IOC_UPDATE			_IOW(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_UPDATE, bool)
#define OLED_SSD1306_IOC_POWER			_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_POWER, _oled_ssd1306_power_t)
#define OLED_SSD1306_IOC_STRING_WIDTH		_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_STRING_WIDTH, _oled_ssd1306_string_width_t)
#define OLED_SSD1306_IOC_BUFFER			_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_BUFFER, _oled_ssd1306_buffer_t)
#define OLED_SSD1306_IOC_INVERT			_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_INVERT, _oled_ssd1306_invert_t)
#define OLED_SSD1306_IOC_SET_CLIPPING		_IOWR(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_SET_CLIPPING, _oled_ssd1306_set_clipping_t)
#define OLED_SSD1306_IOC_SET_OFF_TIMEOUT	_IOW(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_SET_OFF_TIMEOUT, uint64_t)
#define OLED_SSD1306_IOC_GET_PROP		_IOW(OLED_SSD1306_IOC_BASE, _OLED_SSD1306_GET_PROP, _oled_ssd1306_prop_t)

#endif /* __OLED_SSD1306_IOCTL_H__ */

