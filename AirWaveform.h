/**
 * @file AirWaveform.h
 *
 * The definition of class AirWaveform. 
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
#ifndef __AIRWAVEFORM_H__
#define __AIRWAVEFORM_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirWaveform component.
 */
class AirWaveform: public AirObject
{
public: /* methods */
    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirWaveform(uint8_t pid, uint8_t cid, const char *name);
    
    /**
     * Add value to show. 
     *
     * @param ch - channel of waveform(0-3). 
     * @param number - the value of waveform.  
     *
     * @retval true - success. 
     * @retval false - failed. 
     */
    bool addValue(uint8_t ch, uint8_t number);
	
    /**
     * Get bco attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
    uint32_t Get_background_color_bco(uint32_t *number);
	
    /**
     * Set bco attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_background_color_bco(uint32_t number);
	
    /**
     * Get gdc attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
    uint32_t Get_grid_color_gdc(uint32_t *number);	

    /**
     * Set gdc attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_grid_color_gdc(uint32_t number);			
	
    /**
     * Get gdw attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
    uint32_t Get_grid_width_gdw(uint32_t *number);	

    /**
     * Set gdw attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_grid_width_gdw(uint32_t number);			
	
    /**
     * Get gdh attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
    uint32_t Get_grid_height_gdh(uint32_t *number);

    /**
     * Set gdh attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_grid_height_gdh(uint32_t number);			
	
    /**
     * Get pco0 attribute of component
     *
     * @param number - buffer storing data retur
     * @return the length of the data 
     */
    uint32_t Get_channel_0_color_pco0(uint32_t *number);	

    /**
     * Set pco0 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_channel_0_color_pco0(uint32_t number);			
};

/**
 * @}
 */

#endif /* #ifndef __AIRWAVEFORM_H__ */
