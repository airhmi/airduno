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

AirPage::AirPage()
    :AirTouch(0, 0, 0)
{
}

bool AirPage::ChangeScreen(const char *buffer)
{
    String cmd;
    cmd = "CsS(";
    cmd += buffer;
    cmd +=");";
	sendCommand(cmd.c_str());
    return recvRetCommandFinished();    
}