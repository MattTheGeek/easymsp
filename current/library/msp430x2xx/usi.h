#ifndef USI_H
#define USI_H

#ifndef SPI3WIRE
	#define SPI3WIRE 1
#endif

#ifndef SPI_OUTPUT_ONLY
	#define SPI_OUTPUT_ONLY 2
#endif

#ifndef SPI_INPUT_ONLY
	#define SPI_INPUT_ONLY 3
#endif

#ifndef RISING_EDGE
	#define RISING_EDGE 1
#endif

#ifndef FALLING_EDGE
	#define FALLING_EDGE 2
#endif

void spiConfig(unsigned short int, unsigned short int, unsigned short int, unsigned short int);
void spiSetSpeed(unsigned short int);
void usiOff(void);
void spiOut(unsigned char);
unsigned char spiIn(void);


#include "usi.c"

#endif
