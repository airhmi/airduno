/**
 * @file AirShape.h
 *
 * The definition of class AirShape. 
 *
 * @author Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date 2023/11/27
 *
 * @copyright 
 * Copyright (C) 2014-2015 Eyza Teknoloji and Neva Bilisim. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#ifndef __AirShape_H__
#define __AirShape_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirShape component. 
 *
 * Commonly, you want to do something after push and pop it. It is recommanded that only
 * call @ref AirTouch::attachPop to satisfy your purpose. 
 * 
 * @warning Please do not call @ref AirTouch::attachPush on this component, even though you can. 
 */
class AirShape: public AirTouch
{
public: /* methods */

    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirShape(const char *name);

bool Set_active(uint32_t number);

bool Set_left(uint32_t number);


bool Set_top(uint32_t number);

bool Set_width(uint32_t number);

bool Set_height(uint32_t number);

uint32_t Get_left(uint32_t *number);

uint32_t Get_top(uint32_t *number);

uint32_t Get_width(uint32_t *number);

uint32_t Get_height(uint32_t *number);

uint32_t Get_Active(uint32_t *number);


};
#endif /* #ifndef __AirShape_H__ */
