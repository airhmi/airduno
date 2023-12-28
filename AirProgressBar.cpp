/**
 * @file AirProgressBar.cpp
 *
 * The implementation of class AirProgressBar. 
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

#include "AirProgressBar.h"

AirProgressBar::AirProgressBar( const char *name)
    :AirObject(0, 0, name)
{
}


uint32_t AirProgressBar::Set_Value(uint32_t value)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(value, buf, 10);
    cmd = "ProgressBarSet(\"";
    cmd += getObjName();
    cmd += "\",\"Value\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirProgressBar::Set_Color(uint32_t value)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(value, buf, 10);
    cmd = "ProgressBarSet(\"";
    cmd += getObjName();
    cmd += "\",\"Color\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


uint32_t AirProgressBar::Get_Value(uint32_t *value)
{
    String cmd;
    cmd = "ProgressBarGet(\"";
    cmd += getObjName();
    cmd += "\",\"Value\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(value);
}


uint32_t AirProgressBar::Get_Color(uint32_t *value)
{
    String cmd;
    cmd = "ProgressBarGet(\"";
    cmd += getObjName();
    cmd += "\",\"Color\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(value);
}




