#if (defined MSP430F5510) == 1 || (defined __MSP430F5510__) == 1 || (defined  __MSP430F5510) == 1
#	include "device/msp430f5510.h"
#endif

#if (defined MSP430G2553) == 1 || (defined __MSP430G2553__) == 1 || (defined __MSP430G2553) == 1
#	include "device/msp430g2553.h"
#endif

#if (defined MSP430G2452 || defined __MSP430G2452__ || defined __MSP430G2452)
#	include "device/msp430g2452.h"
#endif

#if (defined MSP430G2231 || defined __MSP430G2231__ || defined __MSP430G2231)
#	include "device/msp430g2231.h"
#endif

#if (defined MSP430G2211 || defined __MSP430G2211__ || defined __MSP430G2211)
#	include "device/msp430g2211.h"
#endif

#ifndef SUPPORTEDDEVICE
#	error "EasyMSP is not supported with this device. Please double check your define."
#endif

#include <msp430.h>

