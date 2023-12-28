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

AirPicture::AirPicture( const char *name)
    :AirTouch(0, 0, name)
{
}


uint32_t AirPicture::Get_visible(uint32_t *number)
{
    String cmd;
    cmd = "ImageGet(\"";
    cmd += getObjName();
    cmd += "\",\"Visible\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_left(uint32_t *number)
{
    String cmd;
    cmd = "ImageGet(\"";
    cmd += getObjName();
    cmd += "\",\"Left\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_top(uint32_t *number)
{
    String cmd;
    cmd = "ImageGet(\"";
    cmd += getObjName();
    cmd += "\",\"Top\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_width(uint32_t *number)
{
    String cmd;
    cmd = "ImageGet(\"";
    cmd += getObjName();
    cmd += "\",\"Width\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

uint32_t AirPicture::Get_height(uint32_t *number)
{
    String cmd;
    cmd = "ImageGet(\"";
    cmd += getObjName();
    cmd += "\",\"Height\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}



uint32_t AirPicture::Set_Image_File(String imgName)
{
    char buf[10] = {0};
    String cmd;
    
    //utoa(number, buf, 10);
    cmd = "ImageSet(\"";
    cmd += getObjName();
    cmd += "\",\"Image_File\",\"";
    cmd += imgName;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_active(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImageSet(\"";
    cmd += getObjName();
    cmd += "\",\"Active\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_visible(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImageSet(\"";
    cmd += getObjName();
    cmd += "\",\"Visible\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_left(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImageSet(\"";
    cmd += getObjName();
    cmd += "\",\"Left\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_top(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImageSet(\"";
    cmd += getObjName();
    cmd += "\",\"Top\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_width(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImageSet(\"";
    cmd += getObjName();
    cmd += "\",\"Width\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirPicture::Set_height(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "ImageSet(\"";
    cmd += getObjName();
    cmd += "\",\"Height\",\"";
    cmd += buf;
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}




