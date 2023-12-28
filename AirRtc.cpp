/**
 * @file AirRtc.cpp
 *
 * The implementation of class AirRtc. 
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
#include "AirRtc.h"


bool AirRtc::dateSet(int day,int month,int year)
{
    char sDay[10] = {0};
    char sMonth[10] = {0};
    char sYear[10] = {0};
    
    utoa(day, sDay, 10);
    utoa(month, sMonth, 10);
    utoa(year, sYear, 10);


    String cmd;
    cmd = "dateSet(\"";
    cmd += sDay;
    cmd += "\",\"";
    cmd += sMonth;
    cmd += "\",\"";
    cmd += sYear;    
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool AirRtc::timeSet(int hour,int min)
{
    char sHour[10] = {0};
    char sMin[10] = {0};
    
    utoa(hour, sHour, 10);
    utoa(min, sMin, 10);


    String cmd;
    cmd = "timeSet(\"";
    cmd += sHour;
    cmd += "\",\"";
    cmd += sMin;  
    cmd +="\");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}



