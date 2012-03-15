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
** button.h
** Button driver
**
** Author: Matthew L. Burmeister
** Copyright (c) 2011 All rights reserved.
** ---------------------------------------*/

#ifdef EASYMSP
	#if EASYMSPVER < 1.0
		# error "Button Driver requires EasyMSP 1.0.0 or above."
	#endif
#else
	# error "Button Driver requires EasyMSP."
#endif

#ifndef BUTTON_H
#define BUTTON_H

extern bool read(unsigned short int);

static bool buttonState = false;

bool readButton(unsigned short int);
void buttonSetup(bool);

#include "button.c"

#endif