/**
 * @file AirButton.h
 *
 * The definition of class AirButton. 
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

#ifndef __AIRVARRIABLE_H__
#define __AIRVARRIABLE_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirButton component. 
 *
 * Commonly, you want to do something after push and pop it. It is recommanded that only
 * call @ref AirTouch::attachPop to satisfy your purpose. 
 * 
 * @warning Please do not call @ref AirTouch::attachPush on this component, even though you can. 
 */
class AirVariable: public AirTouch
{
public: /* methods */

    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirVariable(const char *name);

bool VarSeti(uint32_t value);

bool VarSetf(double value);

bool VarSet(String value);

uint32_t VarGeti(void);

double VarGetf(void);

uint16_t VarGet(char *buffer, uint16_t len);
};
/**
 * @}
 */


#endif /* #ifndef __AIRVARRIABLE_H__*/
