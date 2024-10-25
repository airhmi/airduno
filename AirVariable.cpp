/**
 * @file AirVariable.cpp
 *
 * The implementation of class AirText. 
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
#include "AirVariable.h"

AirVariable::AirVariable(const char *name)
    :AirTouch(0, 0, name)
{
}



bool AirVariable::VarSeti(uint32_t value)
{
    char buf[10] = {0};
    String cmd;
    
    sprintf(buf,"%lu",value);
    cmd = "VarSeti(";
    cmd += getObjName();
    cmd += ",";
    cmd += buf;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}



bool AirVariable::VarSetf(double value)
{
    char buf[10] = {0};
    String cmd;
    
    sprintf(buf,"%.04f",value);
    cmd = "VarSet(";
    cmd += getObjName();
    cmd += ",";
    cmd += buf;
    cmd +=");";

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirVariable::VarSet(String value)
{
    String cmd;
    
    cmd = "VarSet(";
    cmd += getObjName();
    cmd += ",";
    cmd += value;
    cmd +=");";

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}


bool isValidNumber(const char *str) {
    // Eğer boş dize ise geçersiz kabul et
    if (*str == '\0') {
        return false;
    }

    bool dotSeen = false;  // Ondalık noktasının daha önce görülüp görülmediğini takip eder

    // Her karakteri kontrol et
    while (*str) {
        if (*str == '.') {
            // Eğer daha önce nokta görülmüşse ikinci bir nokta geçersizdir
            if (dotSeen) {
                return false;
            }
            dotSeen = true;  // İlk defa nokta görülürse işaretlenir
        } 
        else if (!isdigit(*str)) {
            // Sayı değilse ve nokta değilse geçersizdir
            return false;
        }
        str++;
    }

    return true;
}

uint32_t AirVariable::VarGeti(void)
{
    char buffer[100] = {0};
    uint32_t value = 0;
    String cmd;
    uint32_t len = 20;
    uint16_t ret = 0;
    uint32_t start;

    cmd = "VarGet(";
    cmd += getObjName();
    cmd += ",";
    cmd += "NULL";
    cmd +=");";

    start = millis();
    while (millis() - start <= 1000)
    {
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer,len);
        if( ret != 0xFE &&  isValidNumber(buffer) )
        {
            
            break;
        }
    }

    if( isValidNumber(buffer) )
        value = atoi(buffer);

    return value;
}


double AirVariable::VarGetf(void)
{
    uint16_t ret = 0;
    uint32_t start;     
    char buffer[20] = {0}; // Buffer'ı biraz genişlettik
    uint32_t len = 20;
    double floatValue = 0; 

    String cmd;
    cmd = "VarGet(";
    cmd += getObjName();
    cmd += ",";
    cmd += "NULL";
    cmd +=");";

    start = millis();
    while (millis() - start <= 1000)
    {
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer, len);
        if (ret != 0xFE && isValidNumber(buffer))
        {
            //Serial.println(buffer); // Buffer içeriğini yazdır
            break;
        }
    }

    if (isValidNumber(buffer))
    {
        // Ekstra karakterlerden kurtulmak için string'i temizleyin
        String bufferStr(buffer);
        bufferStr.trim();  // Başındaki ve sonundaki boşlukları kaldır
        floatValue = atof(bufferStr.c_str()); // Double'a çevir
    }

    return floatValue;
}

uint16_t AirVariable::VarGet(char *buffer, uint16_t len)
{
    uint16_t ret = 0;
    uint32_t start;     
    uint32_t value = 0;

    String cmd;
    cmd = "VarGet(";
    cmd += getObjName();
    cmd += ",";
    cmd += "NULL";
    cmd +=");";

   start = millis();
    while (millis() - start <= 1000)
    {
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer,len);
        if( ret != 0xFE )
        {
            
            break;
        }
    }

    return ret;    
}






