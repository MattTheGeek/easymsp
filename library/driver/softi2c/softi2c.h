/*

	softi2c.h

*/
#if !(__EASYMSP__)
#	error "\"softi2c\" is a EasyMSP driver and thus requires the EasyMSP system. Ether EasyMSP is not included in this project or this driver is incorrectly included. Reference Code: EASYMSPNOTFOUND"  
#elif !(IO_H)
#	error "\"softiwc\" requires the IO library, which could not be found. This error is most likely an internal error. Reference code: LIBNOTFOUND"
#else
#	ifndef SOFTI2C_H
#	define SOFTI2C_H

unsigned char _SDA;
unsigned char _SCL;

enum i2cMode
{
	Standard	= 1,
	Fast 		= 2,
	FastPlus 	= 3,
	HighSpeed 	= 4,
	UltraFast 	= 5,
}

#include "softi2c.c"

#	endif /* SOFTI2C_h */
#endif /* Main IF */