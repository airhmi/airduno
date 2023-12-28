
@mainpage Home Page

# AirHMI

--------------------------------------------------------------------------------

# Introduction

AirHMI Arduino library provides an easy-to-use way to manipulate AirHMI serial
displays. Users can use the libarry freely, either in commerical projects or 
open-source prjects,  without any additional condiitons. 

For more information about the AirHMI display project, please visit 
https://www.airhmi.com/
This site provdies all the necessary technical documnets, quick start guide, 
tutorials, demos, as well as some useful resources.

To get your AirHMI display, please visit 
https://www.airhmi.com/product

To discuss the project?  Request new features?  Report a BUG? please visit the 
[Forums](https://www.airhmi.com/forum)

# Download Source Code 

Latest version is unstable and a mass of change may be applied in a short time 
without any notification for users. Commonly, it is for developers of this 
library. 


## Latest(unstable)


You can also clone it via git:


## Releases(stable)



All releases can be available from:


# Documentation

Offline Documentation's entry `doc/Documentation/index.html` shiped with source code
can be open in your browser such as Chrome, Firefox or any one you like. 

# Suppported Mainboards

**All boards, which has one or more hardware serial, can be supported.**

For example:

	Arduino Uno: A basic microcontroller-based development board with a wide user base.

	Arduino Mega: A development board with more digital input/output pins and memory.

	Arduino Nano: A compact form-factor microcontroller board often used in embedded projects.

	Arduino Leonardo: A board capable of direct communication with a computer via USB.

	Arduino Due: A board with a 32-bit ARM-based microcontroller.

	Arduino Mini: A small-sized microcontroller board.

	Arduino Yun: A board that combines Arduino and the Linux operating system.

	Arduino Pro Mini: A low-cost, small-sized microcontroller board.

	Arduino MKR Series: Designed specifically for Internet of Things (IoT) applications.

	Arduino Zero: A board with a 32-bit ARM Cortex-M0+ microcontroller.

	ESP8266 Series:

	ESP-01: One of the earliest and most basic ESP8266 modules.
	
	ESP-12E/ESP-12F: More advanced versions with more GPIO pins.
	
	NodeMCU: A development board based on the ESP-12 module, which makes it easier to use in projects.
	
	ESP32 Series:

	ESP32 DevKit V1: A common development board for the ESP32.
	
	NodeMCU-32S: An ESP32-based development board similar to NodeMCU for ESP8266.
	
	Wemos D1 Mini ESP32: A compact ESP32 development board.

# Configuration

In configuration file AirConfig.h, you can find two macros below:

  - dbSerial: Debug Serial (baudrate:9600), needed by beginners for debug your 
    AirHMI applications or sketches. If your complete your work, it will be a 
    wise choice to disable Debug Serial.

  - airSerial: AirHMI Serial, the bridge of AirHMI and your mainboard.

**Note:** the default configuration is for Uno.

## Redirect dbSerial and airSerial

If you want to change the default serial to debug or communicate with AirHMI ,
you need to modify the line in configuration file:

	#define dbSerial Serial    ---> #define dbSerial Serialxxx
    #define airSerial Serial2  ---> #define airSerial Serialxxx

## Disable Debug Serial

If you want to disable the debug information,you need to modify the line in 
configuration file:

    #define DEBUG_SERIAL_ENABLE ---> //#define DEBUG_SERIAL_ENABLE

# UNO-like Mainboards

If your board has only one hardware serial, such as UNO, you should disable 
dbSerial and redirect airSerial to Serial(Refer to section:`Serial configuration`). 

# Useful Links

<https://www.airhmi.com/sample-projects>

<https://www.airhmi.com/education-videos>

<https://www.airhmi.com/instruction>


# License

-------------------------------------------------------------------------------


    The MIT License (MIT) 

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: 
    
    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


-------------------------------------------------------------------------------
