/**
 * @file AirRtc.h
 *
 * The definition of class AirRtc. 
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

#ifndef _AIRRTC_H
#define _AIRRTC_H
     
#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirRtc component.
 */

class AirRtc
{
    public:

bool dateSet(int day,int month,int year);

bool timeSet(int hour,int min);
    
};

/**
 * @}
 */

#endif /* #ifndef __AIRRTC_H__ */