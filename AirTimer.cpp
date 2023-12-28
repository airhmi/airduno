/**
 * @file AirTimer.cpp
 *
 * The implementation of class AirTimer. 
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

#include "AirTimer.h"

AirTimer::AirTimer( const char *name)
    :AirTouch(0, 0, name)
{
}

bool AirTimer::getInterval(uint32_t *value)
{
    String cmd;
    cmd = "TimerGet(\"";
    cmd += getObjName();
    cmd += "\",\"Interval\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(value);
}

bool AirTimer::setInterval(uint32_t value)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(value, buf, 10);
    cmd = "TimerSet(\"";
    cmd += getObjName();
    cmd += "\",\"Interval\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirTimer::enable(void)
{
    String cmd;
    
    cmd = "TimerSet(\"";
    cmd += getObjName();
    cmd += "\",\"1\"";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirTimer::disable(void)
{
    String cmd;
    
    cmd = "TimerSet(\"";
    cmd += getObjName();
    cmd += "\",\"0\"";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

