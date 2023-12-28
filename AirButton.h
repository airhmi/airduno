/**
 * @file AirButton.h
 *
 * The definition of class AirButton. 
 *
 * @author Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date 2023/11/27
 *
 * @copyright 
 * Copyright (C) 2014-2015 Eyza Teknoloji and Neva Bilisim. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#ifndef __AirButton_H__
#define __AirButton_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirButton component. 
 *
 * Commonly, you want to do something after push and pop it. It is recommanded that only
 * call @ref AirTouch::attachPop to satisfy your purpose. 
 * 
 * @warning Please do not call @ref AirTouch::attachPush on this component, even though you can. 
 */
class AirButton: public AirTouch
{
public: /* methods */

    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirButton(const char *name);

    /**
     * Get text attribute of component.
     *
     * @param buffer - buffer storing text returned. 
     * @param len - length of buffer. 
     * @return The real length of text returned. 
     */
    uint16_t getText(char *buffer, uint16_t len);    

    /**
     * Set text attribute of component.
     *
     * @param buffer - text buffer terminated with '\0'. 
     * @return true if success, false for failure. 
     */
    bool setText(const char *buffer);   

    /**
     * Get attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
    uint32_t Get_background_color(uint32_t *number);
	
    /**
     * Set attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_background_color(uint32_t number);
	
    /**
     * Set attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_background_colorTo(uint32_t number);

    /**
     * Get attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
    uint32_t Get_press_background_color(uint32_t *number);	

    /**
     * Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_press_background_color(uint32_t number);			
	
    /**
     * Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_press_background_colorTo(uint32_t number);	

    /**
     * Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_pen_width(uint32_t number);

    /**
     * Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_pen_color(uint32_t number);

    /**
     * Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_pen_colorRGB(String buffer);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool setFont(String buffer);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_font_size(uint32_t number);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_font_name(String buffer);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_font_color(uint32_t number);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_font_colorRGB(String buffer);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_visible(uint32_t number);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_active(uint32_t number);


     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_left(uint32_t number);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_top(uint32_t number);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_width(uint32_t number);

     /* Set bco2 attribute of component
     *
     * @param number - To set up the data
     * @return true if success, false for failure
     */
    bool Set_height(uint32_t number);

    /**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
    uint32_t Get_font_color(uint32_t *number);		
	
    /**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */		
    uint32_t Get_left(uint32_t *number);    
	
    /**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */	    
    uint32_t Get_top(uint32_t *number);  

    /**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */	 
    uint32_t Get_width(uint32_t *number);

    /**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */	 
    uint32_t Get_height(uint32_t *number);

    /**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */	 
    uint32_t Get_visible(uint32_t *number);

    /**
     * Get pco attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */	 
    uint32_t getFont(char *buffer , int len);

};
#endif /* #ifndef __AirButton_H__ */
