/**
 * @file AirConfig.h
 *
 * Options for user can be found here.
 *
 * @author  Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date    2015/8/13
 * @copyright
 * Copyright (C) 2014-2015 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#ifndef __AIRCONFIG_H__
#define __AIRCONFIG_H__

 /**
  * @addtogroup Configuration
  * @{
  */

  /**
   * Define DEBUG_SERIAL_ENABLE to enable debug serial.
   * Comment it to disable debug serial.
   */
   //#define DEBUG_SERIAL_ENABLE

   /**
	* Define dbSerial for the output of debug messages.
	*/
	//#define dbSerial Serial

	/**
	 * Define airSerial for communicate with AirHMI touch panel.
	 */
	#define airSerial Serial
	//#define HW_SERIAL
	/**
	 * Define airSerial for Software Serial.
	 */
	// #include <SoftwareSerial.h>
	// extern SoftwareSerial airSerial;
	// #define AIRHMI_ARDUINO_SOFTWARE_SERIAL
	// #define RX_PIN 10
	// #define TX_PIN 11	 
	/**
	 * Define airSerial for communicate with ESP32 Pin 12 13.
	 */
	//#define airSerial Serial2
	//#define AIRHMI_ESP32_SOFTWARE_SERIAL
	//#define RX_PIN 27
	//#define TX_PIN 26

#ifdef DEBUG_SERIAL_ENABLE
#define dbSerialPrint(a)    dbSerial.print(a)
#define dbSerialPrintln(a)  dbSerial.println(a)
#define dbSerialBegin(a)    dbSerial.begin(a)
#else
#define dbSerialPrint(a)    do{}while(0)
#define dbSerialPrintln(a)  do{}while(0)
#define dbSerialBegin(a)    do{}while(0)
#endif

	 /**
	  * @}
	  */

#endif /* #ifndef __AIRCONFIG_H__ */