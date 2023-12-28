/**
 * @file AirGauge.cpp
 *
 * The implementation of class AirGauge. 
 *
 * @author  Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date    2015/8/13
 * @copyright 
 * Copyright (C) 2014-2015 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "AirGauge.h"

AirGauge::AirGauge(const char *name)
    :AirObject(0, 0, name)
{
}

bool AirGauge::Set_visible(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "GaugeSet(\"";
    cmd += getObjName();
    cmd += "\",\"Visible\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirGauge::Set_left(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "GaugeSet(\"";
    cmd += getObjName();
    cmd += "\",\"Left\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirGauge::Set_top(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "GaugeSet(\"";
    cmd += getObjName();
    cmd += "\",\"Top\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirGauge::Set_radius(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "GaugeSet(\"";
    cmd += getObjName();
    cmd += "\",\"Radius\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirGauge::Set_color(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "GaugeSet(\"";
    cmd += getObjName();
    cmd += "\",\"Color\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirGauge::Set_value(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "GaugeSet(\"";
    cmd += getObjName();
    cmd += "\",\"Value\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

 bool AirGauge::Get_visible(uint32_t *number)
{
    String cmd;
    cmd = "GaugeGet(\"";
    cmd += getObjName();
    cmd += "\",\"Visible\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirGauge::Get_left(uint32_t *number)
{
    String cmd;
    cmd = "GaugeGet(\"";
    cmd += getObjName();
    cmd += "\",\"Left\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirGauge::Get_top(uint32_t *number)
{
    String cmd;
    cmd = "GaugeGet(\"";
    cmd += getObjName();
    cmd += "\",\"Top\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirGauge::Get_radius(uint32_t *number)
{
    String cmd;
    cmd = "GaugeGet(\"";
    cmd += getObjName();
    cmd += "\",\"Radius\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirGauge::Get_color(uint32_t *number)
{
    String cmd;
    cmd = "GaugeGet(\"";
    cmd += getObjName();
    cmd += "\",\"Color\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}


bool AirGauge::Get_value(uint32_t *number)
{
    String cmd;
    cmd = "GaugeGet(\"";
    cmd += getObjName();
    cmd += "\",\"Value\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}
