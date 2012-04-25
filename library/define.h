#ifndef DEFINE_H
#define DEFINE_H

#ifndef __EASYMSP__
#	define __EASYMSP__
#endif

#ifndef EASYMSPVER
#	define EASYMSPVER 1
#endif

#ifndef EASYMSPVERMINOR
#	define EASYMSPVERMINOR 0
#endif

#ifndef NULL
#	define NULL 0
#endif

#ifndef true
#	define true 1
#endif

#ifndef false
#	define false 0
#endif

#ifndef SUCCESS
#	define SUCCESS 0
#endif

#ifndef FAILURE
#	define FAILURE 1
#endif


/* Clock Constants */

#ifndef MCLK
#	define MCLK 1
#endif

#ifndef SMCLK
#	define SMCLK 2
#endif

#ifndef ACLK
#	define ACLK 3
#endif

#ifndef MODOSC
#	define MODOSC 4
#endif

#ifndef DCOCLK
#	define DCOCLK 5
#endif

#ifndef DCOCLKDIV
#	define DCOCLKDIV 6
#endif

#ifndef REFOCLK
#	define REFOCLK 7
#endif

#ifndef XT1CLK
#	define XT1CLK 8
#endif

#ifndef XT2CLK
#	define XT2CLK 9
#endif

#ifndef VLOCLK
#	define VLOCLK 10
#endif

#ifndef XCLK
#	define XCLK 11
#endif

#ifndef CRYSTAL
#	define CRYSTAL 1
#endif

/* IO Port constants */

#ifndef PORTA
#	define PORTA 'A'
#endif

#ifndef PORTB
#	define PORTB 'B'
#endif

#ifndef PORTC
#	define PORTC 'C'
#endif

#ifndef PORTD
#	define PORTD 'D'
#endif

#ifndef PORTE
#	define PORTE 'E'
#endif

#ifndef PORTF
#	define PORTF 'F'
#endif

#ifndef PORTJ
#	define PORTJ 'J'
#endif

#ifndef PORT1
#	define PORT1 1
#endif

#ifndef PORT2
#	define PORT2 2
#endif

#ifndef PORT3
#	define PORT3 3
#endif

#ifndef PORT4
#	define PORT4 4
#endif

#ifndef PORT5
#	define PORT5 5
#endif

#ifndef PORT6
#	define PORT6 6
#endif

#ifndef PORT7
#	define PORT7 7
#endif

#ifndef PORT8
#	define PORT8 8
#endif

#ifndef PORT9
#	define PORT9 9
#endif

#ifndef PORT10
#	define PORT10 10
#endif

#ifndef PORT11
#	define PORT11 11
#endif

#ifndef ON
#	define ON 1
#endif

#ifndef OFF
#	define OFF 0
#endif

#ifndef YES
#	define YES 1
#endif

#ifndef NO
#	define NO 0
#endif

#ifndef HIGH
#	define HIGH 1
#endif

#ifndef LOW
#	define LOW 0
#endif

#ifndef INPUT
#	define INPUT 0
#endif

#ifndef OUTPUT
#	define OUTPUT 1
#endif

#ifndef FALLING
#	define FALLING 0
#endif

#ifndef RISING
#	define RISING 1
#endif

#ifndef LOW_TO_HIGH
#	define LOW_TO_HIGH 1
#endif

#ifndef HIGH_TO_LOW
#	define HIGH_TO_LOW 0
#endif

#ifndef MSBFIRST
#	define MSBFIRST 1
#endif

#ifndef LSBFIRST
#	define LSBFIRST 2
#endif

#ifndef by_1
#	define by_1 1
#endif 

#ifndef by_2
#	define by_2 2
#endif

#ifndef by_4
#	define	by_4 3
#endif

#ifndef by_8
#	define by_8 4
#endif

#ifndef by_16
#	define by_16 5
#endif

#ifndef by_32
#	define	by_32 6
#endif

#ifndef by_64
#	define	by_64 7
#endif

#ifndef by_128
#	define	by_128 8
#endif

#ifndef by_256
#	define	by_256 9
#endif

#ifndef by_512
#	define	by_512 10
#endif

#ifndef by_1024
#	define	by_1024 11
#endif

#ifndef by_8192
#	define	by_8192 12
#endif

#ifndef by_32768
#	define by_32768 13
#endif

#ifndef by_32k
#	define	by_32k 14
#endif

#ifndef by_512k
#	define	by_512k 15
#endif

#ifndef by_8192k
#	define	by_8192k 16
#endif

#ifndef by_128m
#	define	by_128m 17
#endif

#ifndef by_2g
#	define	by_2g 18
#endif

#ifndef by_32K
#	define by_32K by_32k
#endif

#ifndef by_512K
#	define by_512K by_512k
#endif

#ifndef by_8192K
#	define by_8192K by_8192k
#endif

#ifndef by_128M
#	define by_128M by_128m
#endif

#ifndef by_2G
#	define by_2G by_2g
#endif

#ifndef upTo8Mhz
#	define	upTo8Mhz 1
#endif

#ifndef upTo16Mhz
#	define	upTo16Mhz 2
#endif

#ifndef upTo24Mhz
#	define	upTo24Mhz 3
#endif

#ifndef upTo32Mhz
#	define	upTo32Mhz 4
#endif

/* Flash constants */


#ifndef FLASH_KEY1
#	define FLASH_KEY1 0xFEEDFACE
#endif

#ifndef FLASH_KEY2
#	define FLASH_KEY2 0xDEADC0DE
#endif

#ifndef SEGMENTA
#	define SEGMENTA 'A'
#endif

#ifndef SEGMENT_A
#	define SEGMENT_A 'A'
#endif

#ifndef SEGMENTB
#	define SEGMENTB 'B'
#endif

#ifndef SEGMENT_B
#	define SEGMENT_B 'B'
#endif

#ifndef SEGMENTC
#	define SEGMENTC 'C'
#endif

#ifndef SEGMENT_C
#	define SEGMENT_C 'C'
#endif

#ifndef SEGMENTD
#	define SEGMENTD 'D'
#endif

#ifndef SEGMENT_D
#	define SEGMENT_D 'D'
#endif

#ifndef INVALID_KEY
#	define INVALID_KEY 1
#endif

#ifndef SEGMENTS_LOCKED
#	define SEGMENTS_LOCKED 2
#endif

#ifndef SEGMENTA_LOCKED
#	define SEGMENTA_LOCKED 3
#endif

#ifndef INVALID_SEGMENT
#	define INVALID_SEGMENT 4
#endif

#ifndef VOLTAGE_CHANGE
#	define VOLTAGE_CHANGE 5
#endif

typedef char byte;
typedef unsigned short int word;
typedef bool boolean;
typedef char BYTE;
typedef unsigned short int WORD;
typedef bool BOOLEAN;

#endif /* DEFINE_H */
