/**
 * @file AirGraph.cpp
 *
 * The implementation of class AirGraph. 
 *
 * @author  Omer Aygor (email:oaygor@eyzateknoloji.com)
 * @date    2023/12/13
 * @copyright 
 * Copyright (C) 2014-2015 Eyza Teknoloji ve Neva Bilişim \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "AirGraph.h"

AirGraph::AirGraph(const char *name)
    :AirTouch(0, 0, name)
{
}


bool AirGraph::addValue(uint32_t value, uint32_t value2)
{
    char buf[10] = {0};
	char buf2[10] = {0};
    String cmd;
    
    sprintf(buf,"%lu",value);
	sprintf(buf2,"%lu",value2);
    
    cmd = "GAddValue(";
    cmd += getObjName();
    cmd += ",";
    cmd += buf;
	cmd += ",";
    cmd += buf2;
    cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirGraph::Set_line_color(uint32_t value,String buffer)
{
    char buf[10] = {0};
	String cmd;
    
   	sprintf(buf,"%lu",value);
	
    cmd = "GraphSet(";
    cmd += getObjName();
    cmd += ",Line";
    cmd += buf;
    cmd +="_Color,";
	cmd += buffer;
	cmd +=");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

bool AirGraph::clear()
{
    char buf[30] = {0};
    String cmd;
    
    cmd = "GRAPH_Clear(";
    cmd += getObjName();
    cmd += ");";
    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}
