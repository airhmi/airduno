/**
 * @file AirPage.h
 *
 * The definition of class AirPage. 
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

#ifndef __AIRPAGE_H__
#define __AIRPAGE_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * A special component , which can contain other components such as AirButton, 
 * AirText and AirWaveform, etc. 
 */
class AirPage: public AirTouch
{
public: /* methods */
    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirPage(uint8_t pid, uint8_t cid, const char *name);
    
    /**
     * Show itself. 
     * 
     * @return true if success, false for faileure.
     */
    bool show(void);
};
/**
 * @}
 */

#endif /* #ifndef __AIRPAGE_H__ */
