#ifndef MSP430F5510
#define MSP430F5510
#endif

#ifndef __MSP430F5510__
#define __MSP430F5510__
#endif

#include <msp430.h>

#define ISBOARD

#define LED 83
#define BUTTON 8

#define D0 37
#define D1 36
#define D2 0
#define D3 1
#define D4 2
#define D5 3 
#define D6 4
#define D7 5
#define D8 6
#define D9 7
#define D10 32
#define D11 33
#define D12 34
#define D13 35

#define A0 0
#define A1 1
#define A2 2
#define A3 3
#define A4 8
#define A5 9

extern inline void _boardInit(void);

inline void _boardInit(void)
{
	P5SEL = (BIT2 | BIT3 | BIT4 | BIT5); /* Set port5 pins 2 to 5 as Clock inputs */
    P2REN = 0x01;
    P2OUT = 0x01;
    UCSCTL6 = XCAP_2;
    UCSCTL4 = (SELS_5 | SELM_5);
}
