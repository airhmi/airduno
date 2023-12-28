/**
 * @file AirLabel.h
 *
 * The definition of class AirLabel. 
 *
 * @author Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date 2023/12/14
 *
 * @copyright 
 * Copyright (C) 2022-2023 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
 
#ifndef __AIRLABEL_H__
#define __AIRLABEL_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirLabel component.
 */
class AirLabel: public AirTouch
{
public: /* methods */
    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirLabel(const char *name);
    
uint32_t Get_visible(uint32_t *number);

uint32_t Get_left(uint32_t *number);

uint32_t Get_top(uint32_t *number);

uint32_t Get_width(uint32_t *number);

uint32_t Get_height(uint32_t *number);

uint32_t Get_fontSize(uint32_t *number);

uint32_t Get_fontColor(uint32_t *number);

uint16_t getText(char *buffer, uint16_t len);

bool setText(const char *buffer);

uint32_t Set_visible(uint32_t number);

uint32_t Set_left(uint32_t number);

uint32_t Set_top(uint32_t number);

uint32_t Set_width(uint32_t number);

uint32_t Set_height(uint32_t number);

uint32_t Set_fontSize(uint32_t number);

uint32_t Set_fontColor(uint32_t number);
    
};

/**
 * @}
 */

#endif /* #ifndef __AIRLABEL_H__ */
