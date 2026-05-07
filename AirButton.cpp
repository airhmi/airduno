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


bool AirButton::setText(const char *buffer)
{
    String cmd;

    if (!buffer)
        return false;

    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Text,\"";    // virgul/parantez iceren metinler bozulmasin diye tirnaklanir
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_background_color(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    /* .ahi'de renkler signed int (orn. beyaz=-1, kirmizi=-65536). Panel
       atoi() ile parse ediyor. uint32_t bit pattern'ini int32_t olarak
       yazdiririz; boylece kullanici 0xFFFF0000 (=kirmizi) verdiginde
       panel "-65536" alir ve dogru rendere eder. */
    sprintf(buf,"%ld",(int32_t)number);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Color,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_background_colorTo(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%ld",(int32_t)number);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",ColorTo,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_press_background_color(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%ld",(int32_t)number);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Press_Color,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_press_background_colorTo(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%ld",(int32_t)number);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Press_ColorTo,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_pen_width(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    sprintf(buf,"%lu",number);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Pen_Width,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_pen_color(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%ld",(int32_t)number);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Pen_Color,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_pen_colorRGB(String buffer)
{
    String cmd;

    /* Hex (#RRGGBB) string'leri picoc lexer'inin ayriklamamasi icin
       cift tirnak icinde gonderilir; panel CButtonSetEx'e ulasmadan once
       remove_quotes() bu tirnaklari sider. */
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Pen_Color,\"";
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_font_size(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Font_Size,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::setFont(String buffer)
{
    String cmd;

    /* Bosluk iceren font isimleri (orn. "Times New Roman") icin tirnaklama. */
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",FontName,\"";
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/* Set_font_color: panel firmware (03_button.c:396) Font_Color attribute'unu
   normal olarak kabul ediyor. */
bool AirButton::Set_font_color(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%ld",(int32_t)number);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Font_Color,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/* Eski not: "ekranda çalışmadı". Panel kaynagi (03_button.c:396) Font_Color icin
   hem #RRGGBB hex hem decimal int kabul ediyor; eski hata muhtemelen tirnaklamanin
   eksikliginden kaynakliydi. */
bool AirButton::Set_font_colorRGB(String buffer)
{
    String cmd;

    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Font_Color,\"";
    cmd += buffer;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_visible(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    /* Panel firmware'inin CButtonSetEx'i sadece "VISIBLE" kabul ediyor
       (CButtonGetEx aynisini "VIS" ile de kabul ediyor ama Set etmiyor). */
    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Visible,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_active(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_left(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirButton::Set_top(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_width(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::Set_height(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


uint16_t AirButton::getText(char *buffer, uint16_t len)
{
    uint32_t start;
    String cmd;
    uint16_t ret = 0;

    if (!buffer || len == 0)
        return 0;

    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Text,";
    cmd += "NULL";
    cmd +=");";

    start = millis();
    while (millis() - start <= 1000)
    {
        memset(buffer, 0, len);
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer,len);
        if( ret != 0xFE )
        {
            break;
        }
    }

    return ret;
}

uint32_t AirButton::getFont(char *buffer , int len)
{
    uint16_t ret = 0;
    uint32_t start;
    String cmd;

    if (!buffer || len <= 0)
        return 0;

    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",FontName,";
    cmd += "NULL";
    cmd +=");";

    start = millis();
    while (millis() - start <= 1000)
    {
        memset(buffer, 0, len);
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer,len);
        if( ret != 0xFE )
        {
            break;
        }
    }

    return ret;
}

uint32_t AirButton::Get_background_color(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Color,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_press_background_color(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Press_Color,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_font_color(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Font_Color,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_left(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}


uint32_t AirButton::Get_top(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_width(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_height(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_visible(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Visible,";    // Set ile tutarlilik; Get tarafi "Vis" de kabul ediyor.
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* ---------- Panel'in destekledigi ek ozellikler ---------- */

bool AirButton::Set_pushpull(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",PushPull,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirButton::Get_pushpull(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",PushPull,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

bool AirButton::Set_gradient(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "BtnS(";
    cmd += getObjName();
    cmd += ",Gradient,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirButton::Get_gradient(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Gradient,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* ButtonSeti / ButtonSetd: butonun yazisini direkt int / double degerden ayarlar
   (panel firmware'inin destekledigi 3-parametreli kisaltma). */
bool AirButton::setTexti(uint32_t value)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%lu",value);
    cmd = "ButtonSeti(";
    cmd += getObjName();
    cmd += ",";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirButton::setTextf(double value)
{
    char buf[32] = {0};
    String cmd;

    dtostrf(value, 0, 4, buf);
    cmd = "ButtonSetd(";
    cmd += getObjName();
    cmd += ",";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/* Eksik getter'lar */

uint32_t AirButton::Get_press_background_colorTo(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Press_ColorTo,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_active(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_font_size(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Font_Size,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_pen_width(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Pen_Width,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_pen_color(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",Pen_Color,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirButton::Get_background_colorTo(uint32_t *number)
{
    String cmd;
    cmd = "BtnG(";
    cmd += getObjName();
    cmd += ",ColorTo,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}
