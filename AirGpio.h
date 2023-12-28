/**
 * @file AirGpio.h
 *
 * The definition of class AirGpio. 
 *
 * @author Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date 2023/12/14
 *
 * @copyright 
 * Copyright (C) 2022-2023 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#ifndef _AIRGPIO_H
#define _AIRGPIO_H
     
#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirGpio component.
 */

class AirGpio
{
public:

bool digital_write(uint32_t port,uint32_t value);

uint32_t digital_read(uint32_t port);

double analog_read(uint32_t port);

bool set_pwmfreq(uint32_t port ,uint32_t freq , uint32_t duty);
     
};
    
/**
 * @}
 */    
    
#endif /* #ifndef __AIRGPIO_H__ */