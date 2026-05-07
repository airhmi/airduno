/**
 * @file AirPicture.cpp
 *
 * The implementation of class AirPicture. 
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

#include "AirPicture.h"

AirPicture::AirPicture(const char *name)
    :AirTouch(0, 0, name)
{
}


uint32_t AirPicture::Get_visible(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",Vis,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_left(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_top(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_width(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_height(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}



uint32_t AirPicture::Set_Image_File(String imgName)
{
    char buf[16] = {0};
    String cmd;
    
    //utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Image_File,";
    cmd += imgName;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_active(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_visible(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Vis,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_left(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Left,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_top(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Top,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_width(uint32_t number)
{
    char buf[16] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Width,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_height(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Height,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/* ---------- Panel'in destekledigi ek ozellikler ---------- */

uint32_t AirPicture::Get_active(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",Active,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* Blend Color */
uint32_t AirPicture::Set_blendColor(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    sprintf(buf,"%ld",(int32_t)number);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Blend_Color,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Get_blendColor(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",Blend_Color,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* Rotation Angle */
uint32_t AirPicture::Set_rotationAngle(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",RotationAngle,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Get_rotationAngle(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",RotationAngle,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* Rotation Center Left */
uint32_t AirPicture::Set_rotationCenterLeft(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",RotationCenterLeft,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Get_rotationCenterLeft(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",RotationCenterLeft,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* Rotation Center Top */
uint32_t AirPicture::Set_rotationCenterTop(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",RotationCenterTop,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Get_rotationCenterTop(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",RotationCenterTop,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* PushPull */
uint32_t AirPicture::Set_pushpull(uint32_t number)
{
    char buf[16] = {0};
    String cmd;

    utoa(number, buf, 10);
    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",PushPull,";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Get_pushpull(uint32_t *number)
{
    String cmd;
    cmd = "ImG(";
    cmd += getObjName();
    cmd += ",PushPull,";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/* Image_File_Replace */
uint32_t AirPicture::Set_imageFileReplace(String imgName)
{
    String cmd;

    cmd = "ImS(";
    cmd += getObjName();
    cmd += ",Image_File_Replace,";
    cmd += imgName;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}




