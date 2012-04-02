#if defined MSP430F5510 || defined __MSP430F5510__ || defined __MSP430F5510
#	include "device/msp430f5510.h"

#elif defined MSP430G2553 || defined __MSP430G2553__ || defined __MSP430G2553
#	include "device/msp430g2553.h"

#elif defined MSP430G2452 || defined __MSP430G2452__ || defined __MSP430G2452
#	include "device/msp430g2452.h"

#elif defined MSP430G2231 || defined __MSP430G2231__ || defined __MSP430G2231
#	include "device/msp430g2231.h"

#elif defined MSP430G2211 || defined __MSP430G2211__ || defined __MSP430G2211
#	include "device/msp430g2211.h"

#else
#	error "EasyMSP is not supported with this device. Please double check your define."
#endif

#include <msp430.h>

