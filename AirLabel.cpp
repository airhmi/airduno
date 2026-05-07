/**
 * @file AirLabel.cpp
 *
 * The implementation of class AirLabel. 
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
#include "AirLabel.h"

AirLabel::AirLabel( const char *name)
    :AirTouch(0, 0, name)
{
}

uint32_t AirLabel::Get_visible(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Vis,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirLabel::Get_left(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirLabel::Get_top(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirLabel::Get_width(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirLabel::Get_height(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirLabel::Get_fontSize(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",FontSize,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirLabel::Get_fontColor(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Font_Color,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint16_t AirLabel::getText(char *buffer, uint16_t len)
{
    uint16_t ret = 0;
    uint32_t start;
    String cmd;

    if (!buffer || len == 0)
        return 0;

    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Text,";
    cmd += "NULL";
    cmd +=");";

    start = millis();
    while (millis() - start <= 1000)
    {
        memset(buffer, 0, len);   /* iterasyonlar arasi bayat veri olmasin */
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer,len);
        if (ret != 0xFE)
        {
            break;
        }
    }

    return ret;
}


bool AirLabel::setText(const char *buffer)
{
    String cmd;
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Text,\"";
    cmd += buffer;
    cmd +="\");";
	sendCommand(cmd.c_str());
    return recvRetCommandFinished();    
}


uint32_t AirLabel::Set_visible(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Vis,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Set_left(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Set_top(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Set_width(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Set_height(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Set_fontSize(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",FontSize,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Set_fontColor(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    /* Renk panel'de signed int olarak saklanir (.ahi -1 = beyaz, -65536 = kirmizi).
       %ld + (int32_t) cast ile bit pattern dogru parse edilir. */
    sprintf(buf,"%ld",(int32_t)number);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Font_Color,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/* ---------- Panel'in destekledigi ek ozellikler ---------- */

/* setTexti / setTextf : panel firmware'inin LabelSeti / LabelSetd
   3-parametreli kisaltmalari (uart_functions.c PlatformLibrary). */
bool AirLabel::setTexti(uint32_t value)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%lu",value);
    cmd = "LabelSeti(";
    cmd += getObjName();
    cmd += ",";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirLabel::setTextf(double value)
{
    char buf[32] = {0};
    String cmd;

    dtostrf(value, 0, 4, buf);
    cmd = "LabelSetd(";
    cmd += getObjName();
    cmd += ",";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/* Set/Get_active : panel ACTIVE attribute (TRUE/FALSE/1/0) */
bool AirLabel::Set_active(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Get_active(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* Set/Get_fontName : panel FONTNAME attribute (string) */
bool AirLabel::Set_fontName(String buffer)
{
    String cmd;

    /* Bosluklu font isimleri icin tirnaklama (panel remove_quotes() yapar). */
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",FontName,\"";
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::getFontName(char *buffer, int len)
{
    uint16_t ret = 0;
    uint32_t start;
    String cmd;

    if (!buffer || len <= 0)
        return 0;

    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",FontName,";
    cmd += "NULL";
    cmd +=");";

    start = millis();
    while (millis() - start <= 1000)
    {
        memset(buffer, 0, len);
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer, len);
        if (ret != 0xFE)
            break;
    }
    return ret;
}

/* Set/Get_center : panel CENTER attribute (0=sol, 1=orta, 2=sag) */
bool AirLabel::Set_center(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",Center,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirLabel::Get_center(uint32_t *number)
{
    String cmd;
    cmd = "LGet(";
    cmd += getObjName();
    cmd += ",Center,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* Set_scrollEnable : panel SCROLLENABLE (0=off, 1-6=mod). Get yok. */
bool AirLabel::Set_scrollEnable(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",ScrollEnable,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/* Set_scrollSpeed : panel SCROLLSPEED (sure = N*50ms). Get yok. */
bool AirLabel::Set_scrollSpeed(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "LblS(";
    cmd += getObjName();
    cmd += ",ScrollSpeed,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

