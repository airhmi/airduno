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

#ifndef __AirGraph_H__
#define __AirGraph_H__

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
class AirGraph: public AirTouch
{
public: /* methods */

    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirGraph(const char *name);

    /*
     * Set text attribute of component.
     *
     * @param buffer - text buffer terminated with '\0'. 
     * @return true if success, false for failure. 
     */
    bool addValue(uint32_t number, uint32_t number2);   
	
	bool Set_line_color(uint32_t value,String buffer);
    /**
     * Get attribute of component
     *
     * @param number - buffer storing data return
     * @return the length of the data 
     */
	 
	 bool clear();   
	 
};
#endif /* #ifndef __AirGraph_H__ */
