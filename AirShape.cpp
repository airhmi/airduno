/**
 * @file AirShape.cpp
 *
 * The implementation of class AirShape. 
 *
 * @author  Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date    2023/12/13
 * @copyright 
 * Copyright (C) 2014-2015 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "AirShape.h"

AirShape::AirShape( const char *name)
    :AirTouch(0, 0, name)
{
}


bool AirShape::Set_active(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ShapeSet(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirShape::Set_left(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ShapeSet(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirShape::Set_top(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ShapeSet(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirShape::Set_width(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ShapeSet(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirShape::Set_height(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ShapeSet(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}




uint32_t AirShape::Get_left(uint32_t *number)
{
    String cmd;
    cmd = "ShapeGet(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}


uint32_t AirShape::Get_top(uint32_t *number)
{
    String cmd;
    cmd = "ShapeGet(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirShape::Get_width(uint32_t *number)
{
    String cmd;
    cmd = "ShapeGet(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirShape::Get_height(uint32_t *number)
{
    String cmd;
    cmd = "ShapeGet(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirShape::Get_Active(uint32_t *number)
{
    /* BUG fix: onceden ",Vis," gonderiliyordu (panel'de Shape icin
       VIS attribute YOK — sadece ACTIVE var). Get_Active hep null/0
       donuyordu. Simdi panel'in destekledigi ",Active," gonderiliyor. */
    String cmd;
    cmd = "ShapeGet(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}
