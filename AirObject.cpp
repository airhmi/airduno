/**
 * @file AirObject.cpp
 *
 * The implementation of class AirObject. 
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
#include "AirObject.h"

AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name)
{
    this->__pid = 0;
    this->__cid = 0;
    this->__name = name;
}

uint8_t AirObject::getObjPid(void)
{
    return __pid;
}

uint8_t AirObject::getObjCid(void)
{
    return __cid;
}

const char* AirObject::getObjName(void)
{
    return __name;
}

void AirObject::printObjInfo(void)
{
    dbSerialPrint("[");
    dbSerialPrint((uint32_t)this);
    dbSerialPrint(":");
    dbSerialPrint(__pid);
    dbSerialPrint(",");
    dbSerialPrint(__cid);
    dbSerialPrint(",");
    if (__name)
    {
        dbSerialPrint(__name);
    }
    else
    {
        dbSerialPrint("(null)");
    }
    dbSerialPrintln("]");
}

