/**
 * @file AirVariable.cpp
 *
 * The implementation of class AirText. 
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
#include "AirVariable.h"

AirVariable::AirVariable(const char *name)
    :AirTouch(0, 0, name)
{
}



bool AirVariable::VarSeti(uint32_t value)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(value, buf, 10);
    cmd = "VarSet(\"";
    cmd += getObjName();
    cmd += "\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}



bool AirVariable::VarSetf(double value)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(value, buf, 10);
    cmd = "VarSet(\"";
    cmd += getObjName();
    cmd += "\",\"";
    cmd += buf;
    cmd +="\");";

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirVariable::VarSet(String value)
{
    String cmd;
    
    cmd = "VarSet(\"";
    cmd += getObjName();
    cmd += "\",\"";
    cmd += value;
    cmd +="\");";

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirVariable::VarGeti(void)
{
    char buffer[10] = {0};
    uint32_t value = 0;
    String cmd;
    uint32_t len = 20;

    cmd = "VarGet(\"";
    cmd += getObjName();
    cmd += "\",\"";
    cmd += "NULL";
    cmd +="\");";

    sendCommand(cmd.c_str());
    recvRetString(buffer,len);
    value = atoi(buffer);

    return value;
}


double AirVariable::VarGetf(void)
{
    char buffer[10] = {0};
    uint32_t len = 20;
    double floatValue=0; 

    String cmd;
    cmd = "VarGet(\"";
    cmd += getObjName();
    cmd += "\",\"";
    cmd += "NULL";
    cmd +="\");";

    sendCommand(cmd.c_str());
    recvRetString(buffer,len);
    floatValue =atof(buffer);

    return floatValue;
}

uint16_t AirVariable::VarGet(char *buffer, uint16_t len)
{
    uint32_t value = 0;

    String cmd;
    cmd = "VarGet(\"";
    cmd += getObjName();
    cmd += "\",\"";
    cmd += "NULL";
    cmd +="\");";

    sendCommand(cmd.c_str());
    return recvRetString(buffer,len);
}






