/**
 * @file AirHardware.h
 *
 * The definition of base API for using AirHMI. 
 *
 * @author Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date 2023/12/14
 * @copyright 
 * Copyright (C) 2022-2023 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#ifndef __AIRHARDWARE_H__
#define __AIRHARDWARE_H__
#include <Arduino.h>
#include "AirConfig.h"
#include "AirTouch.h"

/**
 * @addtogroup CoreAPI 
 * @{ 
 */

/**
 * Init AirHMI.  
 * 
 * @return true if success, false for failure. 
 */
bool airInit(void);

/**
 * Listen touch event and calling callbacks attached before.
 * 
 * Supports push and pop at present. 
 *
 * @param air_listen_list - index to AirHMI Components list. 
 * @return none. 
 *
 * @warning This function must be called repeatedly to response touch events
 *  from AirHMI touch panel. Actually, you should place it in your loop function. 
 */
void airLoop(AirTouch *air_listen_list[]);

/**
 * @}
 */

bool recvRetNumber(uint32_t *number, uint32_t timeout = 100);
uint16_t recvRetString(char *buffer, uint16_t len, uint32_t timeout = 100);
void sendCommand(const char* cmd);
bool recvRetCommandFinished(uint32_t timeout = 100);

#endif /* #ifndef __AIRHARDWARE_H__ */
