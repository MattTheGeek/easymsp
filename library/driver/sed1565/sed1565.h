#ifndef SED1565_H
#	define SED1565_H

#	ifndef __EASYMSP__
#		error "The driver sed1565 requires EasyMSP to build."
#	endif

enum sedCommands
{
	V5_VOLTAGE_REG_RATIO =			0x20,
	POWER_CONTROLLER_ALL_OFF =		0x28,
	POWER_CONTROLLER_ALL_ON	=		0x2F,
	ELECTRONIC_VOLUME =				0x81,
	ADC_SELECT_NORMAL =				0xA0,
	ADC_SELECT_REVERSE =			0xA1,
	LCD_BIAS_1_9 =					0xA2,
	LCD_BIAS_1_7 =	 				0xA3,
	DISPLAY_ALL_POINTS_OFF =		0xA4,
	DISPLAY_ALL_POINTS_ON =			0xA5,
	DISPLAY_NORMAL =				0xA6,
	DISPLAY_REVERSE	=				0xA7,
	DISPLAY_OFF	=					0xAE,
	DISPLAY_ON =					0xAF,
	COMMON_OUTPUT_MODE_NORMAL =		0xC0,
	COMMON_OUTPUT_MODE_REVERSE = 	0xC8,
	RESET =							0xE2
};

static const unsigned short int _PWR = 0; 
static const unsigned short int _BL = 1;
static const unsigned short int _SDAT = 2;
static const unsigned short int _SCLK = 3;
static const unsigned short int _RST = 4;
static const unsigned short int _DC = 5;
static const unsigned short int _CS = 6;
static const unsigned short int _COMMAND = 1;
static const unsigned short int _DATA = 0;

static void write(unsigned char, const unsigned short int);
extern inline void lcdClear(void);
extern inline void lcdBackLight(unsigned short int);
extern void lcdInit(const unsigned short int*);
static void lcdSetup(void);
extern void lcdCommand(unsigned char);

#include "sed1565.c"

#endif

