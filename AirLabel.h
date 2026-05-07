/**
 * @file AirLabel.h
 *
 * The definition of class AirLabel. 
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
 
#ifndef __AIRLABEL_H__
#define __AIRLABEL_H__

#include "AirTouch.h"
#include "AirHardware.h"
/**
 * @addtogroup Component 
 * @{ 
 */

/**
 * AirLabel component.
 */
class AirLabel: public AirTouch
{
public: /* methods */
    /**
     * @copydoc AirObject::AirObject(uint8_t pid, uint8_t cid, const char *name);
     */
    AirLabel(const char *name);
    
uint32_t Get_visible(uint32_t *number);

uint32_t Get_left(uint32_t *number);

uint32_t Get_top(uint32_t *number);

uint32_t Get_width(uint32_t *number);

uint32_t Get_height(uint32_t *number);

uint32_t Get_fontSize(uint32_t *number);

uint32_t Get_fontColor(uint32_t *number);

uint16_t getText(char *buffer, uint16_t len);

bool setText(const char *buffer);

uint32_t Set_visible(uint32_t number);

uint32_t Set_left(uint32_t number);

uint32_t Set_top(uint32_t number);

uint32_t Set_width(uint32_t number);

uint32_t Set_height(uint32_t number);

uint32_t Set_fontSize(uint32_t number);

uint32_t Set_fontColor(uint32_t number);

/* ---------- Panel'in destekledigi ek ozellikler ---------- */

/**
 * Convenience setter: write label text directly from an integer.
 * Sends the firmware's LabelSeti() command (3-parametreli).
 */
bool setTexti(uint32_t value);

/**
 * Convenience setter: write label text directly from a double.
 * Sends the firmware's LabelSetd() command (3-parametreli, dtostrf).
 */
bool setTextf(double value);

/**
 * Set/Get ACTIVE attribute (etkin/etkin-degil — touch event yaniti).
 * @param number 1 = etkin, 0 = pasif.
 */
bool Set_active(uint32_t number);
uint32_t Get_active(uint32_t *number);

/**
 * Set/Get FONTNAME attribute (font ailesi adi).
 * Bosluklu adlar (orn. "Times New Roman") icin tirnaklama otomatik.
 */
bool Set_fontName(String buffer);
uint32_t getFontName(char *buffer, int len);

/**
 * Set/Get CENTER attribute (yatay metin hizalama).
 * @param number 0 = sola yasli, 1 = ortalanmis, 2 = saga yasli (panel'de TLabel.Center).
 */
bool Set_center(uint32_t number);
uint32_t Get_center(uint32_t *number);

/**
 * Set SCROLLENABLE attribute (kaydirma animasyon modu, sadece ELabel).
 * 0 = kapali, 1-6 = kaydirma modlari (panel CLabelSetEx icindeki
 * GUI_ANIM mantigina gore yon ve hiz farkliligi yaratir).
 * Panel-side write-only — Get yoktur.
 */
bool Set_scrollEnable(uint32_t number);

/**
 * Set SCROLLSPEED attribute (kaydirma animasyon hizi, sadece ELabel).
 * Sure = number * 50ms (orn. 6 = 300ms varsayilan).
 * Panel-side write-only — Get yoktur.
 */
bool Set_scrollSpeed(uint32_t number);

};

/**
 * @}
 */

#endif /* #ifndef __AIRLABEL_H__ */
