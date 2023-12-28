/**
 * @file AirGauge.h
 *
 * The definition of class AirGauge. 
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
 
#ifndef __AIRGAUGE_H__
#define __AIRGAUGE_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirGauge component.
 */
class AirGauge: public AirObject
{
public: /* methods */
    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirGauge( const char *name);

bool Set_visible(uint32_t number);

bool Set_left(uint32_t number);

bool Set_top(uint32_t number);

bool Set_radius(uint32_t number);

bool Set_color(uint32_t number);

bool Set_value(uint32_t number);

 bool Get_visible(uint32_t *number);

bool Get_left(uint32_t *number);

bool Get_top(uint32_t *number);

bool Get_radius(uint32_t *number);

bool Get_color(uint32_t *number);

bool Get_value(uint32_t *number);
		
};

/**
 * @}
 */

#endif /* #ifndef __AIRGAUGE_H__ */
