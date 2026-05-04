/**
 * @file AirVariable.cpp
 *
 * The implementation of class AirVariable.
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
    char buf[16] = {0};
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
    char buf[32] = {0};
    String cmd;

    // dtostrf, AVR Arduino'da çalışmayan sprintf("%f") yerine taşınabilir çözümdür.
    dtostrf(value, 0, 4, buf);
    cmd = "VarSetf(";
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

    // İsteğe bağlı işaret karakterini atla ('+' veya '-')
    if (*str == '-' || *str == '+') {
        str++;
        // Sadece işaretten ibaretse geçersiz
        if (*str == '\0') {
            return false;
        }
    }

    bool dotSeen = false;   // Ondalık noktasının daha önce görülüp görülmediğini takip eder
    bool digitSeen = false; // En az bir rakam görüldü mü

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
        else {
            digitSeen = true;
        }
        str++;
    }

    return digitSeen;
}

uint32_t AirVariable::VarGeti(void)
{
    char buffer[32] = {0};
    uint32_t value = 0;
    String cmd;
    uint16_t len = sizeof(buffer) - 1;   // son byte daima '\0' kalsın
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
        memset(buffer, 0, sizeof(buffer));
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer,len);
        if( ret != 0xFE &&  isValidNumber(buffer) )
        {
            break;
        }
    }

    if( isValidNumber(buffer) )
        value = strtoul(buffer, NULL, 10);

    return value;
}


double AirVariable::VarGetf(void)
{
    uint16_t ret = 0;
    uint32_t start;
    char buffer[32] = {0};
    uint16_t len = sizeof(buffer) - 1;   // son byte daima '\0' kalsın
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
        memset(buffer, 0, sizeof(buffer));
        sendCommand(cmd.c_str());
        ret = recvRetString(buffer, len);
        if (ret != 0xFE && isValidNumber(buffer))
        {
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

    if (!buffer || len == 0)
    {
        return 0;
    }

    String cmd;
    cmd = "VarGet(";
    cmd += getObjName();
    cmd += ",";
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






