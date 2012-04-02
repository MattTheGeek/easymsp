#ifndef DEFINE_H
#define DEFINE_H

#ifndef __EASYMSP__
#define __EASYMSP__
#endif

#ifndef EASYMSPVER
#define EASYMSPVER 1
#endif

#ifndef EASYMSPVERMINOR
#define EASYMSPVERMINOR 0
#endif

#ifndef NULL
	#define NULL 0
#endif

#ifndef true
	#define true 1
#endif

#ifndef false
	#define false 0
#endif

#define bitSet(data,bit) data |= (1 << bit)
#define bitClear(data, bit) data &= ~(1 << bit)
#define testBit(data, bit, result) {if (data & bit){return(1);}else{return(0);}}

typedef char byte;
typedef unsigned short int word;
typedef bool boolean;
typedef char BYTE;
typedef unsigned short int WORD;
typedef bool BOOLEAN;

#define MCLK 1
#define SMCLK 2
#define ACLK 3
#define MODOSC 4
#define DCOCLK 5
#define REFOCLK 6
#define XT1CLK 7
#define XT2CLK 8
#define VLOCLK 9
#define XCLK 10

#define PORTA 'A'
#define PORTB 'B'
#define PORTC 'C'
#define PORTD 'D'
#define PORTE 'E'
#define PORTF 'F'
#define PORTJ 'J'

#define PORT1 1
#define PORT2 2
#define PORT3 3
#define PORT4 4
#define PORT5 5
#define PORT6 6
#define PORT7 7
#define PORT8 8
#define PORT9 9
#define PORT10 10
#define PORT11 11

#define ON 1
#define OFF 0

#define YES 1
#define NO 0

#define HIGH 1
#define LOW 0

#define INPUT 0
#define OUTPUT 1

#define FALLING 0
#define RISING 1

#define LOW_TO_HIGH 1
#define HIGH_TO_LOW 0

#define MSBFIRST 1
#define LSBFIRST 2

#define by_2 1
#define	by_4 2
#define by_8 3
#define by_16 4
#define	by_32 5
#define	by_64 6
#define	by_128 7
#define	by_256 8
#define	by_512 9
#define	by_1024 10
#define	by_8192 11
#define by_32768 12
#define	by_32k 13
#define	by_512k 14
#define	by_8192k 15
#define	by_128m 16
#define	by_2g 17

#define by_32K by_32k
#define by_512K by_512k
#define by_8192K by_8192k
#define by_128M by_128m
#define by_2G by_2g

#define	upTo8Mhz 1
#define	upTo16Mhz 2
#define	upTo24Mhz 3
#define	upTo32Mhz 4

#endif /* DEFINE_H */
