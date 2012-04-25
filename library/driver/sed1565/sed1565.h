#ifndef SED1565_H
#	define SED1565_H

#	ifndef __EASYMSP__
#		error "The driver sed1565 requires EasyMSP to build."
#	endif

#define LCD_SCLK_PIN 6
#define LCD_SDATA_PIN 5 
#define LCD_CS_PIN 4
#define LCD_DC_PIN 3 
#define LCD_ON_PIN 2 
#define LCD_BL_PIN 1
#define LCD_RESET_PIN 0 

#	define V5_VOLTAGE_REG_RATIO	0x20
#	define POWER_CONTROLLER_ALL_OFF	0x28
#	define POWER_CONTROLLER_ALL_ON		0x2F
#	define ELECTRONIC_VOLUME		0x81
#	define ADC_SELECT_NORMAL		0xA0
#	define ADC_SELECT_REVERSE		0xA1
#	define LCD_BIAS_1_9			0xA2
#	define LCD_BIAS_1_7			0xA3
#	define DISPLAY_ALL_POINTS_OFF	0xA4
#	define DISPLAY_ALL_POINTS_ON	0xA5
#	define DISPLAY_NORMAL			0xA6
#	define DISPLAY_REVERSE			0xA7
#	define DISPLAY_OFF				0xAE
#	define DISPLAY_ON				0xAF
#	define COMMON_OUTPUT_MODE_NORMAL	0xC0
#	define COMMON_OUTPUT_MODE_REVERSE	0xC8
#	define RESET					0xE2

#endif

static void writelcd(unsigned char, unsigned short int);