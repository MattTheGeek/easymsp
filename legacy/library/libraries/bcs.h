/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	bcs.h
 *	Basic Clock System Plus (BCS+) library for EasyMSP.   
 *
 *	Part of the EasyMSP Project
 *	www.code.google.com/p/EasyMSP/
 *
 *	Author: Matthew L. Burmeister
 *	Copyright (c) 2010, 2011, 2012 All rights reserved.
 *
 *	Contact
 *		You can contact me by email at matthewburmeister@gmail.com 
 *		or by sending mail to:
 *
 *		Matthew Burmeister
 *		11593 Autunno St
 *		Las Vegas, NV 89183
 *		United States of America
 *
 *	Licence
 *		EasyMSP is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		EasyMSP is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with EasyMSP. If not, see <http://www.gnu.org/licenses/>.
 *
*/

#ifndef BCS_H
#define BCS_H
extern void BCSState(unsigned short int);
extern unsigned short int setMCLK(unsigned short int, unsigned short int);
extern unsigned short int setSMCLK(unsigned short int, unsigned short int);
extern unsigned short int setACLK(unsigned short int, unsigned short int);
extern unsigned short int setDCO(unsigned short int);
/*
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
*/

#endif
