/**
 * @file AirBuzzer.cpp
 *
 * The implementation of class AirBuzzer. 
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

#include "AirBuzzer.h"

AirBuzzer::AirBuzzer( const char *name)
    :AirTouch(0, 0, name)
{
}


bool AirBuzzer::Set_Buzzer(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd = "BuzzerSet(";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


