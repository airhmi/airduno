/**
 * @file AirTouch.cpp
 *
 * The implementation of class AirTouch. 
 *
 * @author Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date 2023/12/14
 * @copyright 
 * Copyright (C) 2022-2023 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#include "AirTouch.h"


AirTouch::AirTouch(uint8_t pid, uint8_t cid, const char *name)
    :AirObject(pid, cid, name)
{
    this->__cb_push = NULL;
    this->__cb_pop = NULL;
    this->__cbpop_ptr = NULL;
    this->__cbpush_ptr = NULL;
}

void AirTouch::attachPush(AirTouchEventCb push, void *ptr)
{
    this->__cb_push = push;
    this->__cbpush_ptr = ptr;
}

void AirTouch::detachPush(void)
{
    this->__cb_push = NULL;
    this->__cbpush_ptr = NULL;
}

void AirTouch::attachPop(AirTouchEventCb pop, void *ptr)
{
    this->__cb_pop = pop;
    this->__cbpop_ptr = ptr;
}

void AirTouch::detachPop(void)
{
    this->__cb_pop = NULL;    
    this->__cbpop_ptr = NULL;
}

void AirTouch::push(void)
{
    if (__cb_push)
    {
        __cb_push(__cbpush_ptr);
    }
}

void AirTouch::pop(void)
{
    if (__cb_pop)
    {
        __cb_pop(__cbpop_ptr);
    }
}

void AirTouch::iterate(AirTouch **list, uint8_t pid, uint8_t cid, String name ,  int32_t event)
{
    AirTouch *e = NULL;
    uint16_t i = 0;

    if (NULL == list)
    {
        return;
    }
    
   

    for(i = 0; (e = list[i]) != NULL; i++)
    {

        if (String(e->getObjName()) == name )
        {
             
            e->printObjInfo();
            if (AIR_EVENT_PUSH == event)
            {
                e->push();
            }
            else if (AIR_EVENT_POP == event)
            {
                e->pop();
            }
            
            break;
        }
    }
}

