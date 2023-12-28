/**
 * @file AirWaveform.cpp
 *
 * The implementation of class AirWaveform. 
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
#include "AirWaveform.h"

AirWaveform::AirWaveform(uint8_t pid, uint8_t cid, const char *name)
    :AirObject(pid, cid, name)
{
}

bool AirWaveform::addValue(uint8_t ch, uint8_t number)
{
    char buf[15] = {0};
    
    if (ch > 3)
    {
        return false;
    }
    
    sprintf(buf, "add %u,%u,%u", getObjCid(), ch, number);

    sendCommand(buf);
    return true;
}

uint32_t AirWaveform::Get_background_color_bco(uint32_t *number)
{
    String cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirWaveform::Set_background_color_bco(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".bco=";
    cmd += buf;
    sendCommand(cmd.c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirWaveform::Get_grid_color_gdc(uint32_t *number)
{
    String cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdc";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirWaveform::Set_grid_color_gdc(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".gdc=";
    cmd += buf;
    sendCommand(cmd.c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirWaveform::Get_grid_width_gdw(uint32_t *number)
{
    String cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdw";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirWaveform::Set_grid_width_gdw(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".gdw=";
    cmd += buf;
    sendCommand(cmd.c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirWaveform::Get_grid_height_gdh(uint32_t *number)
{
    String cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdh";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirWaveform::Set_grid_height_gdh(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".gdh=";
    cmd += buf;
    sendCommand(cmd.c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirWaveform::Get_channel_0_color_pco0(uint32_t *number)
{
    String cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco0";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirWaveform::Set_channel_0_color_pco0(uint32_t number)
{    
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".pco0=";
    cmd += buf;
    sendCommand(cmd.c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}
 
