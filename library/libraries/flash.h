/*
 *
 *
 *
 *
 *
 *
 *
 *
 */
#ifndef __EASYMSP__
	# error "Module flash requires EasyMSP."
#endif

#ifndef FLASH_H
#define FLASH_H
 
#ifndef SEGMENTA
	#define SEGMENTA 0
#endif

#ifndef SEGMENTB
	#define SEGMENTB 1
#endif

#ifndef SEGMENTC
	#define SEGMENTC 2
#endif

#ifndef SEGMENTD
	#define SEGMENTD 3
#endif

extern unsigned short int setCPUFreq(unsigned short int);
extern unsigned short int getCPUFreq(void);

unsigned short int* getDCOCal(void);
unsigned short int checkCalData(unsigned short int);
unsigned short int writeDCOCal(unsigned short int*);
//User Prototypes
unsigned short int flashRead(unsigned short int);
unsigned short int flashWrite(unsigned short int*, unsigned short int);
unsigned short int flashAppend(unsigned short int, unsigned short int);
unsigned short int flashErase(unsigned short int,  unsigned short int);
//Vars

#include "flash.c"

#endif
