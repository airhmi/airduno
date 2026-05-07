/**
 * @file AirPicture.h
 *
 * The definition of class AirPicture. 
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

#ifndef __AIRPICTURE_H__
#define __AIRPICTURE_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirPicture component. 
 */
class AirPicture: public AirTouch
{
public: /* methods */

AirPicture( const char *name);

uint32_t Get_visible(uint32_t *number);

uint32_t Get_left(uint32_t *number);

uint32_t Get_top(uint32_t *number);

uint32_t Get_width(uint32_t *number);

uint32_t Get_height(uint32_t *number);

uint32_t Set_Image_File(String imgName);

uint32_t Set_active(uint32_t number);

uint32_t Set_visible(uint32_t number);

uint32_t Set_left(uint32_t number);

uint32_t Set_top(uint32_t number);

uint32_t Set_width(uint32_t number);

uint32_t Set_height(uint32_t number);

/* ---------- Panel'in destekledigi ek ozellikler ---------- */

/**
 * Eksik Get_active — Set_active'in karsiligi. (panel ACTIVE attribute)
 */
uint32_t Get_active(uint32_t *number);

/**
 * Set/Get BLEND_COLOR (resim uzerine renk filtresi/tinting).
 * Renk signed int, panel'de Blend_Color field'inda saklanir.
 */
uint32_t Set_blendColor(uint32_t number);
uint32_t Get_blendColor(uint32_t *number);

/**
 * Set/Get ROTATIONANGLE (derece, 0..359).
 */
uint32_t Set_rotationAngle(uint32_t number);
uint32_t Get_rotationAngle(uint32_t *number);

/**
 * Set/Get ROTATIONCENTERLEFT, ROTATIONCENTERTOP (pivot noktasi).
 */
uint32_t Set_rotationCenterLeft(uint32_t number);
uint32_t Get_rotationCenterLeft(uint32_t *number);
uint32_t Set_rotationCenterTop(uint32_t number);
uint32_t Get_rotationCenterTop(uint32_t *number);

/**
 * Set/Get PUSHPULL (basili tutma modu, AirButton ile ayni mantik).
 */
uint32_t Set_pushpull(uint32_t number);
uint32_t Get_pushpull(uint32_t *number);

/**
 * IMAGE_FILE_REPLACE: panel'in image data'sini runtime'da degistirir
 * (replace path).
 */
uint32_t Set_imageFileReplace(String imgName);

};

#endif /* #ifndef __AIRPICTURE_H__ */
