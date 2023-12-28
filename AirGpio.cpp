/**
 * @file AirGpio.cpp
 *
 * The implementation of class AirGpio. 
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
#include "AirGpio.h"


bool AirGpio::digital_write(uint32_t port,uint32_t value)
{
    char buf[10] = {0};
    char gp[10] = {0};

    if( port < 0 || port > 7)
        return false;

    String cmd;
    String gpio = "GPIO_";

    utoa(port, gp, 10);
    gpio += gp;

    utoa(value, buf, 10);
    cmd = "GPIO_Write(";
    cmd += gpio;
    cmd += ",";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

uint32_t AirGpio::digital_read(uint32_t port)
{
    uint32_t number;
    char buf[10] = {0};
    char gp[10] = {0};

    if( port < 0 || port > 7)
        return false;

    String cmd;
    String gpio = "GPIO_";

    utoa(port, gp, 10);
    gpio += gp;

    cmd = "GPIO_Read(";
    cmd += gpio;
    cmd += ",";
    cmd += "NULL";
    cmd +=");";
    sendCommand(cmd.c_str());
    recvRetNumber(&number);
    return number;
}

double AirGpio::analog_read(uint32_t port)
{
    char buf[10] = {0};
    char buffer[100];
    int len = 0;

    utoa(port, buf, 10);
    
    String cmd;
    cmd = "ADC_Read(";
    cmd += buf;
    cmd += ",\"Text\",\"";
    cmd += "NULL";
    cmd +="\");";
    sendCommand(cmd.c_str());
    recvRetString(buffer,len); 

    return atof(buffer);
}

bool AirGpio::set_pwmfreq(uint32_t port ,uint32_t freq , uint32_t duty)
{
    char par1[10] = {0};
    char par2[10] = {0};
    char par3[10] = {0};

    if( port < 0 || port > 3)
        return false;

    utoa(port, par1, 10);
    utoa(freq, par2, 10);
    utoa(duty, par3, 10);

    String cmd;
    cmd = "PWM_Set(";
    cmd += par1;
    cmd += ",";
    cmd += par2;
    cmd += ",";
    cmd += par3;  
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

