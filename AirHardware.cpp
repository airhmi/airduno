/**
 * @file AirHardware.cpp
 *
 * The implementation of base API for using AirHMI. 
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
#include "AirHardware.h"

#define AIR_RET_CMD_FINISHED            (0x01)
#define AIR_RET_EVENT_LAUNCHED          (0x88)
#define AIR_RET_EVENT_UPGRADED          (0x89)
#define AIR_RET_EVENT_TOUCH_HEAD            (0x65)     
#define AIR_RET_EVENT_POSITION_HEAD         (0x67)
#define AIR_RET_EVENT_SLEEP_POSITION_HEAD   (0x68)
#define AIR_RET_CURRENT_PAGE_ID_HEAD        (0x66)
#define AIR_RET_STRING_HEAD                 (0x70)
#define AIR_RET_NUMBER_HEAD                 (0x71)
#define AIR_RET_INVALID_CMD             (0x00)
#define AIR_RET_INVALID_COMPONENT_ID    (0x02)
#define AIR_RET_INVALID_PAGE_ID         (0x03)
#define AIR_RET_INVALID_PICTURE_ID      (0x04)
#define AIR_RET_INVALID_FONT_ID         (0x05)
#define AIR_RET_INVALID_BAUD            (0x11)
#define AIR_RET_INVALID_VARIABLE        (0x1A)
#define AIR_RET_INVALID_OPERATION       (0x1B)
#define AIR_CONNECT                     (0x1C)
/*
 * Receive uint32_t data. 
 * 
 * @param number - save uint32_t data. 
 * @param timeout - set timeout time. 
 *
 * @retval true - success. 
 * @retval false - failed.
 *
 */
bool recvRetNumber(uint32_t *number, uint32_t timeout)
{

    char buffer[100];
    int len = 100;

    memset(buffer,0x00,sizeof(buffer));

    recvRetString(buffer,len);

    *number = atoi(buffer);

    return true;

/*
    bool ret = false;
    uint8_t temp[8] = {0};

    if (!number)
    {
        goto __return;
    }
    
    airSerial.setTimeout(timeout);
    if (sizeof(temp) != airSerial.readBytes((char *)temp, sizeof(temp)))
    {
        goto __return;
    }

    if (temp[0] == AIR_RET_NUMBER_HEAD
        && temp[5] == 0xFF
        && temp[6] == 0xFF
        && temp[7] == 0xFF
        )
    {
        *number = ((uint32_t)temp[4] << 24) | ((uint32_t)temp[3] << 16) | (temp[2] << 8) | (temp[1]);
        ret = true;
    }

__return:

    if (ret) 
    {
        dbSerialPrint("recvRetNumber :");
        dbSerialPrintln(*number);
    }
    else
    {
        dbSerialPrintln("recvRetNumber err");
    }
    
    return ret;
    */
}


/*
 * Receive string data. 
 * 
 * @param buffer - save string data. 
 * @param len - string buffer length. 
 * @param timeout - set timeout time. 
 *
 * @return the length of string buffer.
 *
 */
uint16_t recvRetString(char *buffer, uint16_t len, uint32_t timeout)
{
    uint16_t ret = 0;
    bool str_start_flag = false;
    uint8_t cnt_0xff = 0;
    String temp = String("");
    uint8_t c = 0;
    long start;
    int state = 0;

    if (!buffer || len == 0)
    {
        goto __return;
    }
    
    start = millis();
    while (millis() - start <= timeout)
    {

        while (airSerial.available())
        {
            if(state == 0 )
            {
                c = airSerial.read();
                
                if ('\n' == c)
                {
                    state++;
                }
                else
                {
                    temp += (char)c;
                }
            }
            else if(state == 1 )
            {
                c = airSerial.read();
                if ('O' == c)
                    state++;    
            }
            else if(state == 2 )
            {
                c = airSerial.read();
                if ('K' == c)
                    state++;    
            }
            else if(state == 3 )
            {
                c = airSerial.read();
                if ('\n' == c)
                {
                    break;
                }   
            }

        }
    }

    ret = temp.length();
    ret = ret > len ? len : ret;
    strncpy(buffer, temp.c_str(), ret);
    
__return:

    dbSerialPrint("recvRetString[");
    dbSerialPrint(temp.length());
    dbSerialPrint(",");
    dbSerialPrint(temp);
    dbSerialPrintln("]");

    return ret;
}

/*
 * Send command to AirHMI.
 *
 * @param cmd - the string of command.
 */
void sendCommand(const char* cmd)
{
    while (airSerial.available())
    {
        airSerial.read();
    }
    
    airSerial.print(cmd);
    //airSerial.write(0xFF);
    //airSerial.write(0xFF);
    //airSerial.write(0xFF);
}


/*
 * Command is executed successfully. 
 *
 * @param timeout - set timeout time.
 *
 * @retval true - success.
 * @retval false - failed. 
 *
 */
bool recvRetCommandFinished(uint32_t timeout)
{    
    uint16_t ret = 0;
    String temp = String("");
    uint8_t c = 0;
    long start;
    int state = 0;
    
    start = millis();
    while (millis() - start <= timeout)
    {

        while (airSerial.available())
        {
            if(state == 0 )
            {
                c = airSerial.read();
                if ('O' == c)
                    state++;    
            }
            else if(state == 1 )
            {
                c = airSerial.read();
                if ('K' == c)
                    state++;    
            }
            else if(state == 2 )
            {
                c = airSerial.read();
                if ('\n' == c)
                {
                    ret = true;
                    break;
                }   
            }

        }
    }

    return ret;
}

int airDunoConnect = 0;
uint32_t airDunoSendTimeout = 0;

bool airInit(void)
{
    int timeout = 1000;
    bool ret = false;
    bool ret2 = false;
    uint32_t start;
    int event;
    uint8_t c;  
    
    //dbSerialBegin(115200);
    airSerial.begin(115200);

	//airSerial.print("INIT start;");
	
    while(ret == false)
    {
        if( ( airDunoConnect == 0 )  && ( millis() - airDunoSendTimeout ) > 5000 )
        {
            airSerial.print("ArduinoReq();");
            airDunoSendTimeout = millis();
        }

        while (airSerial.available() > 0)
        {   
            delay(10);
            c = airSerial.read();
            
            if (AIR_RET_EVENT_TOUCH_HEAD == c)
            {
                start = millis();
                while (millis() - start <= timeout && ret == false )
                {

                    while (airSerial.available())
                    {
                        event = airSerial.read();
                        if( event == AIR_CONNECT )
                        {
                            airDunoConnect = 1;
                            //airSerial.print("Connect ok;");
                            ret = true;
                        }
                        
                        break;  
                    }
                }
            }
        }

    }

    //airSerial.print("INIT OK;");
	//delay(1000);
	
	return true;
    //sendCommand("");
    //sendCommand("bkcmd=1");
    //ret1 = recvRetCommandFinished();
    //sendCommand("page 0");
    //ret2 = recvRetCommandFinished();
    //return ret1 && ret2;
}




// Sample Data:  0x65 0x01 BUTTON2 \n
void airLoop(AirTouch *air_listen_list[])
{
    static uint8_t __buffer[10];
    
    uint16_t i;
    uint8_t c;  
    uint32_t start;
    String temp = String("");
    uint16_t ret = 0;
    int event; 
    int timeout = 1000;





    
    while (airSerial.available() > 0)
    {   
        //delay(10);
        c = airSerial.read();
        
		//airSerial.println("HERE1");
		
        if (AIR_RET_EVENT_TOUCH_HEAD == c)
        {
            //airSerial.println("HERE2");
            ret = false;
            start = millis();
            while (millis() - start <= timeout && ret == false )
            {

                while (airSerial.available())
                {
                    event = airSerial.read();
                    ret = true;
                    break;  
                }
            }

            if( ret == false )
                return;

            ret = false;
            start = millis();
            while (millis() - start <= timeout && ret == false)
            {

                while (airSerial.available())
                {
                    c = airSerial.read();
                    if ('\n' == c)
                    {
                        ret = true;
                        break;
                    }
                    else
                    {
                        temp += (char)c;
                    }   
                }
            }

            if(ret == true)
            {
				//airSerial.print(temp);
                AirTouch::iterate(air_listen_list, 0, 0,temp, event);
            }

/*
            if (airSerial.available() >= 6)
            {
                __buffer[0] = c;  
                for (i = 1; i < 7; i++)
                {
                    __buffer[i] = airSerial.read();
                }
                __buffer[i] = 0x00;
                
                if (0xFF == __buffer[4] && 0xFF == __buffer[5] && 0xFF == __buffer[6])
                {
                    AirTouch::iterate(air_listen_list, __buffer[1], __buffer[2], (int32_t)__buffer[3]);
                }
                
            }

            */
        }
    }
}

