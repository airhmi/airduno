/**
 * @file AirButton.cpp
 *
 * The implementation of class AirButton. 
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

#include "AirButton.h"

AirButton::AirButton( const char *name)
    :AirTouch(0, 0, name)
{
}


// ok
bool AirButton::setText(const char *buffer)
{
    String cmd;
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Text\",\"";
    cmd += buffer;
    cmd +="\");";
	sendCommand(cmd.c_str());
    return recvRetCommandFinished();    
}

bool AirButton::Set_background_color(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Color\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_background_colorTo(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"ColorTo\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_press_background_color(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Press_Color\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_press_background_colorTo(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Press_ColorTo\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_pen_width(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Pen_Width\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_pen_color(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Pen_Color\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_pen_colorRGB(String buffer)
{
    String cmd;
    
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Pen_Color\",\"";
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_font_size(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Font_Size\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::setFont(String buffer)
{
    String cmd;
    
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"FontName\",\"";
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

// ekranda çalışmadı
bool AirButton::Set_font_color(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Font_Color\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

// ekranda çalışmadı
bool AirButton::Set_font_colorRGB(String buffer)
{
    String cmd;
    
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Font_Color\",\"";
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_visible(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Visible\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_active(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Active\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_left(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Left\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_top(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Top\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_width(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Width\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_height(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ButtonSet(\"";
    cmd += getObjName();
    cmd += "\",\"Height\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


uint16_t AirButton::getText(char *buffer, uint16_t len)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Text\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetString(buffer,len);
}

uint32_t AirButton::getFont(char *buffer , int len)
{
    String cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".font";
    sendCommand(cmd.c_str());
    
    return recvRetString(buffer,len);
}

uint32_t AirButton::Get_background_color(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Color\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_press_background_color(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Press_Color\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_font_color(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Font_Color\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_left(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Left\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}


uint32_t AirButton::Get_top(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Top\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_width(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Width\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_height(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Height\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_visible(uint32_t *number)
{
    String cmd;
    cmd = "ButtonGet(\"";
    cmd += getObjName();
    cmd += "\",\"Visible\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}
