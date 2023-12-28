/**
 * @file AirPage.cpp
 *
 * The implementation of class AirPage. 
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

#include "AirPage.h"

AirPage::AirPage(uint8_t pid, uint8_t cid, const char *name)
    :AirTouch(pid, cid, name)
{
}

bool AirPage::show(void)
{
    uint8_t buffer[4] = {0};

    const char *name = getObjName();
    if (!name)
    {
        return false;
    }
    
    String cmd = String("page ");
    cmd += name;
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

