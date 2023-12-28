/**
 * @file AirTimer.h
 *
 * The definition of class AirTimer. 
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

#ifndef __AIRTIMER_H__
#define __AIRTIMER_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirTimer component. 
 *
 * Commonly, you want to do something after set timer cycle and enable it,and the cycle value 
 * must be greater than 50
 * 
 */
class AirTimer: public AirTouch
{
public: /* methods */

    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirTimer(const char *name);

bool getInterval(uint32_t *value);

bool setInterval(uint32_t value);

bool enable(void);

bool disable(void);

};
/**
 * @}
 */


#endif /* #ifndef __AIRTIMER_H__ */
