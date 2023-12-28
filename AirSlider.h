/**
 * @file AirSlider.h
 *
 * The definition of class AirSlider. 
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

#ifndef __AIRSLIDER_H__
#define __AIRSLIDER_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirSlider component. 
 */
class AirSlider: public AirTouch
{
public: /* methods */
    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirSlider( const char *name);

uint32_t Set_Value(uint32_t value);

uint32_t Set_Color(uint32_t value);

uint32_t Get_Value(uint32_t *value);

uint32_t Get_Color(uint32_t *value);
	
};
/**
 * @}
 */


#endif /* #ifndef __AIRSLIDER_H__ */
