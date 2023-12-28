/**
 * @file AirTouch.h
 *
 * The definition of class AirTouch. 
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

#ifndef __AIRTOUCH_H__
#define __AIRTOUCH_H__

#include <Arduino.h>
#include "AirConfig.h"
#include "AirObject.h"

/**
 * @addtogroup TouchEvent 
 * @{ 
 */

/**
 * Push touch event occuring when your finger or pen coming to AirHMI touch pannel. 
 */
#define AIR_EVENT_PUSH  (0x01)

/**
 * Pop touch event occuring when your finger or pen leaving from AirHMI touch pannel. 
 */
#define AIR_EVENT_POP   (0x02)  

/**
 * Type of callback funciton when an touch event occurs. 
 * 
 * @param ptr - user pointer for any purpose. Commonly, it is a pointer to a object. 
 * @return none. 
 */
typedef void (*AirTouchEventCb)(void *ptr);

/**
 * Father class of the components with touch events.  
 *
 * Derives from AirObject and provides methods allowing user to attach
 * (or detach) a callback function called when push(or pop) touch event occurs.
 */
class AirTouch: public AirObject
{
public: /* static methods */    
    static void iterate(AirTouch **list, uint8_t pid, uint8_t cid,String name, int32_t event);

public: /* methods */

    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirTouch(uint8_t pid, uint8_t cid, const char *name);

    /**
     * Attach an callback function of push touch event. 
     *
     * @param push - callback called with ptr when a push touch event occurs. 
     * @param ptr - parameter passed into push[default:NULL]. 
     * @return none. 
     *
     * @note If calling this method multiply, the last call is valid. 
     */
    void attachPush(AirTouchEventCb push, void *ptr = NULL);

    /**
     * Detach an callback function. 
     * 
     * @return none. 
     */
    void detachPush(void);

    /**
     * Attach an callback function of pop touch event. 
     *
     * @param pop - callback called with ptr when a pop touch event occurs. 
     * @param ptr - parameter passed into pop[default:NULL]. 
     * @return none. 
     *
     * @note If calling this method multiply, the last call is valid. 
     */
    void attachPop(AirTouchEventCb pop, void *ptr = NULL);

    /**
     * Detach an callback function. 
     * 
     * @return none. 
     */
    void detachPop(void);
    
private: /* methods */ 
    void push(void);
    void pop(void);
    
private: /* data */ 
    AirTouchEventCb __cb_push;
    void *__cbpush_ptr;
    AirTouchEventCb __cb_pop;
    void *__cbpop_ptr;
};

/**
 * @}
 */

#endif /* #ifndef __AIRTOUCH_H__ */
