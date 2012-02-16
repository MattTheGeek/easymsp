/* ---------------------------------------------------------------------------
** 
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
** led.h
** LED driver
**
** Author: Matthew L. Burmeister
** Copyright (c) 2011 All rights reserved.
** ---------------------------------------*/

#ifndef LED_H
#define LED_H

#ifndef RED_LED
	#define RED_LED 0
#endif

#ifndef GREEN_LED
	#define GREEN_LED 6
#endif

extern void high(unsigned short int);
extern void low(unsigned short int);

void ledOn(unsigned short int);
void ledOff(unsigned short int);
void lcdBlink(unsigned short int, unsigned short int);

#include "led.c"

#endif