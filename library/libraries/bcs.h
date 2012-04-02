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
** bcs.h
** Provides Basic Clock system support.
**
** Author: Matthew L. Burmeister
** Copyright (c) 2011 All rights reserved.
** -------------------------------------------------------------------------*/
#ifndef BCS_H
#define BCS_H


#define M16 16000
#define M12 12000
#define M8 8000
#define M6 6000
#define M4 4000
#define M2 2000
#define M1 1000
#define K500 500
#define K125 125
#define K32	32
#define K22 22
#define K2	2
#define DAMNSLOW 2

#define DCOCLK 1
#define DCO 1
#define VLOCLK 2
#define VLO 2
#define LFXT1SCLK 3
#define CRYSTAL 3
#define DIGITALCLK 4
#define DIGITAL 4

static volatile unsigned short int currentcpuspeed = NULL;

unsigned short int setCPUFreq(unsigned short int speed);
/**
 \brief Changes the CPU operating frequency
 \detail setCPUFreq() changes the CPU operating frequency/speed. setCPUFreq() will also adjust delay and timing settings to account for the increase or decrease of CPU speed.

 \param[in] speed Speed to would like to change the CPU to in Khz.
 \li 16000 - 16Mhz
 \li 12000 - 12Mhz
 \li 8000 - 8Mhz
 \li 6000 - 6Mhz
 \li 4000 - 4Mhz
 \li 2000 - 2Mhz
 \li 1000 - 1Mhz
 \li 500 - 500Khz
 \li 125 - 125Khz
 \li 32 - 32Khz (Requires crystal)
 \li 22 - 22Khz
 \li DAMNSLOW (or 2) - Around 2.2Khz

 \note Frequencies above 1Mhz require that the MSP430 have full calibration data in it's info segment. You can use a MSP430 with pre-written data or run a calibration tool.

 \return 0 on success
 \return 1 invaild selection
 \return 2 out of range
 \return 3 Calibration data does not exist

*/
unsigned short int setCPUFreq(unsigned short int speed);

unsigned short int setDCOFreq(unsigned short int, unsigned short int, unsigned short int);

unsigned short int setMCLK(unsigned short int, unsigned short int);
unsigned short int setSMCLK(unsigned short int, unsigned short int);
unsigned short int setACLK(unsigned short int, unsigned short int);

void disableDCO(void);
void enableDCO(void);

unsigned short int getCPUFreq(void);

#include "bcs.c"

#endif
