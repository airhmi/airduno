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
#include <SoftwareSerial.h>

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


/* ========================================================================
 * Pending touch event buffer
 *
 * Problem: Arduino setText/Set/VarSet komut gonderdikten sonra
 * recvRetCommandFinished veya recvRetString icinde belirli pattern bekler.
 * Bu sirada panel kullanicidan touch alirsa AIR_RET_EVENT_TOUCH_HEAD ile
 * baslayan event Arduino RX bufferina dusuyor. recvRet state makinesi
 * beklenmeyen byte gelince airSerial.read ile yutuyor -> event kayboluyor.
 *
 * Cozum: recvRet state==0 iken AIR_RET_EVENT_TOUCH_HEAD goruunce o ve
 * sonraki byteleri newline gelene kadar global pending buffera kopyala.
 * airLoop her cagrida once bu bufferi parse et ve AirTouch::iterate cagir.
 * ======================================================================== */
#define AIR_PENDING_BUF_SIZE  40
static uint8_t pendingEventBuf[AIR_PENDING_BUF_SIZE];
static uint8_t pendingEventLen = 0;
static bool    pendingEventCapturing = false;
static bool    pendingEventReady     = false;

/* Beklenmeyen byte recvRet tarafindan gormesi durumunda burayi cagir.
 * AIR_RET_EVENT_TOUCH_HEAD gorulurse capture baslar, sonraki byteler
 * newline gelene kadar buffera kopyalanir. true donerse byte tuketildi. */
static bool capturePendingTouchByte(uint8_t c)
{
    if (!pendingEventCapturing)
    {
        if (c == AIR_RET_EVENT_TOUCH_HEAD && !pendingEventReady)
        {
            pendingEventCapturing = true;
            pendingEventLen       = 0;
            pendingEventBuf[pendingEventLen++] = c;
            return true;
        }
        return false;
    }
    /* capturing aktif */
    if (pendingEventLen < AIR_PENDING_BUF_SIZE)
        pendingEventBuf[pendingEventLen++] = c;
    if (c == '\n' || pendingEventLen >= AIR_PENDING_BUF_SIZE)
    {
        pendingEventCapturing = false;
        pendingEventReady     = true;
    }
    return true;
}


#ifdef AIRHMI_ARDUINO_SOFTWARE_SERIAL	 
	SoftwareSerial airSerial(RX_PIN, TX_PIN);//arduino için software tanımlamada bu kod açılır
#endif
//SoftwareSerial airSerial(12, 13);//arduino için software tanımlamada bu kod açılır
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
    int len = sizeof(buffer) - 1;   // recvRetString'in strncpy'si null koymadigi
                                    // icin son byte daima '\0' kalsin.
    uint16_t ret = 0;

    if (!number)
        return false;

    memset(buffer,0x00,sizeof(buffer));

    /* timeout PARAMETRESI artik recvRetString'e gecirilir (eskiden bu
       deger goz ardi ediliyordu, default 100ms kullaniliyordu). Ayrica
       Get_* metodlarinin default timeout'u 1000ms'ye yukseltildi (bkz.
       AirHardware.h). Bu olmadan simulator yanitlari 100ms'den uzun
       suren hallerde Arduino timeout edip 0 okuyordu. */
    ret = recvRetString(buffer, len, timeout);

    /* AVR Arduino'da atoi() 16-bit `int` donduruyor; -16728065 gibi renk
       degerleri burada kesiliyordu. strtol() 32-bit ve isaretli (negatif
       renk degerleri icin) dogru parse eder. */
    *number = (uint32_t)strtol(buffer, NULL, 10);

    return ret > 0;

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
uint16_t recvRetString_(char *buffer, uint16_t len, uint32_t timeout)
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
                    break;
                }
                else
                {
                    temp += (char)c;
                }
            }
            /*
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
            */

        }
    }

    ret = temp.length();
    if( ret > 0  )
    {
        ret = ret > len ? len : ret;
        strncpy(buffer, temp.c_str(), ret);
    }
    
__return:

    dbSerialPrint("recvRetString[");
    dbSerialPrint(temp.length());
    dbSerialPrint(",");
    dbSerialPrint(temp);
    dbSerialPrintln("]");

    return ret;
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
	bool loop = true;
	
    if (!buffer || len == 0)
    {
        goto __return;
    }
    
    
    start = millis();
    while (millis() - start <= timeout && loop)
    {
        if (!airSerial.available())
            continue;

        int peeked = airSerial.peek();

        /* state==0 iken touch event head gelirse buffer'da birak. */
        if (state == 0 && (uint8_t)peeked == AIR_RET_EVENT_TOUCH_HEAD)
            break;

        c = (uint8_t)airSerial.read();

        if (state == 0)
        {
            if (0x01 == c) state++;
            /* bilinmeyen byte: cope */
        }
        else if (state == 1)
        {
            if (0x7E == c) state++;
            else           temp += (char)c;
        }
        else if (state == 2)
        {
            if (0x6F == c)
            {
                state++;
                loop = false;
                break;
            }
            else
            {
                /* 0x6F gelmedi - 0x7E once normal data idi. */
                temp += (char)0x7E;
                temp += (char)c;
                state = 1;
            }
        }
    }



    if( state == 3 )
    {
        ret = temp.length();
        if( ret > 0  )
        {
            ret = ret > len ? len : ret;
            strncpy(buffer, temp.c_str(), ret);
        }
    }
    else
    {
        ret = 0xFE;
    }
    
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
    /* Bu fonksiyon eskiden buffer'i sessizce temizliyordu (event byteleri
       cope giderdi). Simdi buffer'daki her byte'i capturePendingTouchByte'a
       sokuyoruz - 0x65 ile baslayan touch eventleri kaybolmaz. */
    while (airSerial.available())
    {
        uint8_t c = airSerial.read();
        capturePendingTouchByte(c);
    }

    airSerial.print(cmd);
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
    bool ret = false;
    int peeked;
    long start;
    int state = 0;

    start = millis();
    while (millis() - start <= timeout && state < 4)
    {
        if (!airSerial.available())
            continue;

        peeked = airSerial.peek();

        /* Touch event head: cevabin parcasi degil. Buffer'da birak ki
           airLoop normal flow'unda parse etsin. Hemen don, recvRet'in false
           donmesi setText icin sorun olmaz (cagiran return degerini
           kullanmiyor). */
        if ((uint8_t)peeked == AIR_RET_EVENT_TOUCH_HEAD)
            return false;

        /* state-based pattern matching */
        if (state == 0)
        {
            if ('O' == peeked) { airSerial.read(); state++; }
            else                 airSerial.read();   /* bilinmeyen byte, cope */
        }
        else if (state == 1)
        {
            if ('K' == peeked) { airSerial.read(); state++; }
            else               { state = 0; }
        }
        else if (state == 2)
        {
            if (0x0a == peeked) { airSerial.read(); state++; }
            else                { state = 0; }
        }
        else if (state == 3)
        {
            if (0x0d == peeked) { airSerial.read(); state++; ret = true; }
            else                { state = 0; }
        }
    }

    return ret;
}

int airDunoConnect = 0;
uint32_t airDunoSendTimeout = 0;

/* ---------- Bagsanti watchdog ---------- */
/* Panel/simulator'dan en son veri alindigi zaman. Cron icinde gelen
   kucuk paketler bile (touch, framed yanitlar) bunu canli tutar. */
static uint32_t airLastSeenMs = 0;
/* Yeniden el sıkısma denemeleri arasi minimum sure (ms). */
static const uint32_t AIR_RECONNECT_RETRY_MS = 5000;
/* Bu sure boyunca panel'den hicbir veri gelmezse "disconnected" say. */
static const uint32_t AIR_DISCONNECT_TIMEOUT_MS = 15000;

bool airIsConnected(void)
{
    return airDunoConnect == 1;
}

void airReconnect(void)
{
    /* Connect flag'ini dusur, bir sonraki airLoop iterasyonu hemen
       ArduinoReq() gonderebilsin. */
    airDunoConnect = 0;
    airDunoSendTimeout = millis() - AIR_RECONNECT_RETRY_MS - 1;
}

bool airInit(void)
{
    int timeout = 1000;
    bool ret = false;
    bool ret2 = false;
    uint32_t start;
    int event;
    uint8_t c;  
    
    //dbSerialBegin(115200);
    //airSerial.begin(115200);	
#ifdef HW_SERIAL	
	airSerial.begin(115200);//arduino için software tanımlamada bu kod açılır
#endif

#ifdef AIRHMI_ARDUINO_SOFTWARE_SERIAL	
	airSerial.begin(115200);//arduino için software tanımlamada bu kod açılır
#endif
	
#ifdef AIRHMI_ESP32_SOFTWARE_SERIAL	
	airSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN); // Software Serial için bu kod açılır pin numaraları tanımlanır.AirConfig'den Serial2 yapılır.
#endif	
	//airSerial.print("INIT start;");
	
    while(ret == false)
    {
        if( ( airDunoConnect == 0 )  && ( millis() - airDunoSendTimeout ) > 5000 )
        {
            airSerial.print("ArduinoReq();\n");
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
                            airSerial.print("FunctionsResponseSet(1);");
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

    /* ---------- Pending touch event: recvRet sirasinda yakalanmis 0x65
       paketleri varsa burada normal event mantigiyla isle. ---------- */
    if (pendingEventReady && pendingEventLen >= 3 &&
        pendingEventBuf[0] == AIR_RET_EVENT_TOUCH_HEAD)
    {
        int     pe_event = pendingEventBuf[1];
        String  pe_temp  = String("");
        for (uint8_t pi = 2; pi < pendingEventLen; pi++)
        {
            uint8_t pc = pendingEventBuf[pi];
            if (pc == '\n') break;
            pe_temp += (char)pc;
        }
        airLastSeenMs = millis();
        AirTouch::iterate(air_listen_list, 0, 0, pe_temp, pe_event);
        pendingEventLen   = 0;
        pendingEventReady = false;
    }
    /* Half-captured (newline gelmedi) durumunu da temizle ki bir sonraki
       0x65 baslangici icin yer olsun. */
    /* (apostrof yok) */
    if (pendingEventReady)
    {
        pendingEventLen   = 0;
        pendingEventReady = false;
    }

    /* ---------- Watchdog: bagsanti koparsa otomatik yeniden bagsla ----------
       1) Connect flag aktif ama panel'den uzun suredir veri yoksa flag'i dusur.
       2) Connect flag pasif iken periyodik ArduinoReq() gonder. Cevap geldiginde
          (asagida AIR_CONNECT yakalandiginda) flag tekrar aktif olur. */
    if (airDunoConnect == 1 && airLastSeenMs != 0 &&
        (millis() - airLastSeenMs) > AIR_DISCONNECT_TIMEOUT_MS)
    {
        airDunoConnect = 0;
        airDunoSendTimeout = millis() - AIR_RECONNECT_RETRY_MS - 1;
    }

    if (airDunoConnect == 0 &&
        (millis() - airDunoSendTimeout) > AIR_RECONNECT_RETRY_MS)
    {
        airSerial.print("ArduinoReq();\n");
        airDunoSendTimeout = millis();
    }





    
    while (airSerial.available() > 0)
    {
        //delay(10);
        c = airSerial.read();
        airLastSeenMs = millis();   /* panel canli — herhangi bir veri geldi */

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

            /* Re-handshake yaniti: panel ArduinoReq()'a karsilik
               AIR_RET_EVENT_TOUCH_HEAD ardindan AIR_CONNECT gonderir.
               Connect olmamissa bunu yakalayip flag'i ayarla. */
            if (airDunoConnect == 0 && ret == true && event == AIR_CONNECT)
            {
                airDunoConnect = 1;
                airSerial.print("FunctionsResponseSet(1);");
                continue;
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

