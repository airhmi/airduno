/**
 * @file AirObject.h
 *
 * The definition of class AirObject. 
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
#ifndef __AIROBJECT_H__
#define __AIROBJECT_H__
#include <Arduino.h>
#include "AirConfig.h"
/**
 * @addtogroup CoreAPI 
 * @{ 
 */

/**
 * Root class of all AirHMI components. 
 *
 * Provides the essential attributes of a AirHMI component and the methods accessing
 * them. At least, Page ID(pid), Component ID(pid) and an unique name are needed for
 * creating a component in Airiton library. 
 */
class AirObject 
{
public: /* methods */

    /**
     * Constructor. 
     *
     * @param pid - page id. 
     * @param cid - component id.    
     * @param name - pointer to an unique name in range of all components. 
     */
    AirObject(uint8_t pid, uint8_t cid, const char *name);

    /**
     * Print current object'address, page id, component id and name. 
     *
     * @warning this method does nothing, unless debug message enabled. 
     */
    void printObjInfo(void);

protected: /* methods */

    /*
     * Get page id.
     *
     * @return the id of page.  
     */
    uint8_t getObjPid(void);    

    /*
     * Get component id.
     *
     * @return the id of component.  
     */
    uint8_t getObjCid(void);

    /*
     * Get component name.
     *
     * @return the name of component. 
     */
    const char *getObjName(void);    
    
private: /* data */ 
    uint8_t __pid; /* Page ID */
    uint8_t __cid; /* Component ID */
    const char *__name; /* An unique name */
};
/**
 * @}
 */

#endif /* #ifndef __AIROBJECT_H__ */
