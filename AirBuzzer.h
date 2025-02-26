/**
 * @file AirBuzzer.h
 *
 * The definition of class AirBuzzer. 
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

#ifndef __AirBuzzer_H__
#define __AirBuzzer_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirBuzzer component. 
 *
 * Commonly, you want to do something after push and pop it. It is recommanded that only
 * call @ref AirTouch::attachPop to satisfy your purpose. 
 * 
 * @warning Please do not call @ref AirTouch::attachPush on this component, even though you can. 
 */
class AirBuzzer: public AirTouch
{
public: /* methods */

    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirBuzzer(const char *name);

    /**
     * Get text attribute of component.
     *
     * @param buffer - buffer storing text returned. 
     * @param len - length of buffer. 
     * @return The real length of text returned. 
     */
    bool Set_Buzzer(uint32_t number);    


};
#endif /* #ifndef __AirBuzzer_H__ */
