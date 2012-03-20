/*
 * io.c
 * Version: 1.0.4
 * Library for accessing ports
 *
 * Author: Matthew Burmeister
 * Copyright Matthew Burmeister 2011 - 2012. All Rights Reserved.
 *
 * Part of the EasyMSP Project.
 *
 */

/* Info
 *
 *	Library merge
 *		Since the library merge of the 2 series library and the newer 5 series library, the IO library is split up into three sections. The First section is for global functions
 *		that rely on the lower level functions below.
 *
 *		The second section is the 2 series (or just 8-bit port) library functions. and the third is currently the 5 series (16 bit port) library functions.
 *
 *		The library will issue a preprocessor error if the device series is not declared or incorrect.
 *
 *	Function Name Changes
 *		Most function names have been changed, as they were quite vague on what they do. A example would be readPin(), since read() could mean anything and the old input() and
 *		output() functions have been consolidated into one specific function, pinMode(). However, this change does break compatibility with obsolete versions.
 *
 *	Inlining
 *		All functions should created inline, as if the exact code was generated, the code size and processing time would increase substantially and performance will deteriorate.
 *
 *	Bitmasks
 *		EasyMSP generates bitmasks by shifting 1 by x times.
 *
 *	Figuring out ports
 *		The IO library determines what port to operate on by following a simple algorithm.
 *
 *		If pin is less than or equal to the (port width - 1)...
 *			Operate on port and return.
 *		if pin is higher than the (port width - 1)
 *			Subtract the port width from pin.
 *			Goto next port block if it exists, otherwise subtract again and goto the next port block.
 *
 */

#ifdef IO_H

/* Functions for all series */
#if SERIES == 2 || SERIES == 5

inline void digitalWrite(unsigned short int pin, unsigned short int state)
{
	if (state == HIGH)
	{
		setHigh(pin);
	}
	else if (state == LOW)
	{
		setLow(pin);
	}
	else
	{
		return;
	}
}

#endif /* End All device block */

/* Functions for 2 Series Devices */
#if SERIES == 2

inline void setHigh(unsigned short int pin)
{

#ifdef HASPORT1 /* Does the device has PORT1? */
	
	if (pin <= 7) /* If pin is equal or less than 7, then we operate on PORT1 */
	{
		/* We need to generate a bitmask for P1OUT, we do this by shifting 0x01 by pin. This produces a bitmask that for the desired bit and pin. */

		P1OUT |= (1 << pin); /* OR the generated bit mask to PxOUT to set the bit and make the pin high */
		return;
	}

#endif /* HASPORT1 */
	
	pin = pin - 8; /* Since the value was higher than 8, subtract by 8 and later compare */

	/* The next code blocks are generally the same as above. */

#ifdef HASPORT2 /* Does the device has PORT2? */
	
	if (pin <= 7)
	{
		P2OUT |= (1 << pin);
		return;
	}

#endif /* HASPORT2 */
	
	pin = pin - 8;

#ifdef HASPORT3 /* Does the device has PORT3? */
	
	if (pin <= 7)
	{
		P3OUT |= (1 << pin);
		return;
	}

#endif /* HASPORT3 */
	
#ifdef HASPORT4 /* Does the device has PORT4? */

	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT |= (1 << pin);
	}

#endif /* HASPORT4 */
	
	return; /* Return from the last function or the pin was out of range. */
}

inline void setLow(unsigned short int pin)
{

#ifdef HASPORT1 /* Does the device has PORT1? */
	
	if (pin <= 7) /* If pin is equal or less than 7, then we operate on PORT1 */
	{
		/* We need to generate a bitmask for P1OUT, we do this by shifting 0x01 by pin. This produces a bitmask that for the desired bit and pin. */

		P1OUT &= ~(1 << pin); /* NAND the generated bit mask to PxOUT to clear the bit and set the pin low */

		return; /* Feturn from function */
	}

#endif /* HASPORT1 */
	
	pin = pin - 8; /* Since the value was higher than 8, subtract by 8 and later compare */

	/* The next code blocks are generally the same as above. */

#ifdef HASPORT2  /* Does the device has PORT2? */
	
	if (pin <= 7)
	{
		P2OUT &= ~(1 << pin);

		return;
	}

#endif /* HASPORT2 */
	
	pin = pin - 8;

#ifdef HASPORT3  /* Does the device has PORT3? */
	
	if (pin <= 7)
	{
		P3OUT &= ~(1 << pin);

		return;
	}

#endif /* HASPORT3 */
	
#ifdef HASPORT4  /* Does the device has PORT4? */
	
	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT &= ~(1 << pin);
	}

#endif /* HASPORT4 */
	
	return; /* Return from the last function or the pin was out of range. */
}

inline void pinMode(unsigned short int pin, unsigned short int state)
{

	if (state > 1) /* Check for invaild state */
	{
		return; /* State was higher than 1, return */

		/* Since we have two states
		 *
		 * INPUT 0
		 * OUTPUT 1
		 *
		 * we can assume that anything higher is invaild.
		 *
		 */
	}

#ifdef HASPORT1 /* Does the device have PORT1? */

	if (pin <= 7) /* Is pin equal or lower to 7? */
	{
		if (state == OUTPUT)
		{
			/* If the state is output, We need to set the PxDIR bit */

			P1DIR |= (1 << pin); /* Produce bitmask by shifting 1 by pin, and then OR to PxDIR */
		}
		else
		{
			/* Otherwise we can assume state is input, So we need to clear the PxDIR bit */

			P1DIR &= ~(1 << pin); /* Produce bitmask by shifting 1 by pin, and then NAND to PxDIR */
		}

		return; /* Return */
	}

#endif /* HASPORT1 */

	pin = pin - 8; /* Since the pin is higher than 8, subtract by 8 and then compare again. */

	/* The next blocks of code are like the above block */

#ifdef HASPORT2 /* Does the device have PORT2 */

	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P2DIR |= (1 << pin);
		}
		else
		{
			P2DIR &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORT2 */

	pin = pin - 8;

#ifdef HASPORT3 /* Does the device have PORT3? */
	
	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P3DIR |= (1 << pin);
		}
		else
		{
			P3DIR &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORT3 */

#ifdef HASPORT4 /* Does the device has PORT4? */
	
	pin = pin - 8;

	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P4DIR |= (1 << pin);
		}
		else
		{
			P4DIR &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORT4 */

	return;
}

inline bool readPin(unsigned short int pin)
{

#ifdef HASPORT1
	
	if (pin <= 7) /* is pin less than or equal to 7? Then operate on PORT1 */
	{
		/* We get the state of the pin by doing a bitwise AND between PxIN and the calculated bitmask */

		auto unsigned short int result = P1IN & (1 << pin);

		/* If the value stored in result is not zero, then the bit was set (pin was high). */

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			/* Otherwise, if the value stored in result IS zero, than the bit is cleared (pin is low). */

			return(LOW);
		}
	}

#endif /* HASPORT1 */

	pin = pin - 8; /* Subtract 8 from pin since pin was higher than 8 */
	
	/* The next blocks of code are like the above block */

#ifdef HASPORT2
	
	if (pin <= 7)
	{
		auto unsigned short int result = P2IN & (1 << pin);

		if (result > 0)
		{
			return (HIGH);
		}
		else
		{
			return (LOW);
		}

	}

#endif /* HASPORT2 */
	
	pin = pin - 8;

#ifdef HASPORT3
	
	if (pin <= 7)
	{
		auto unsigned short int result = P3IN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return (LOW);
		}
	}

#endif /* HASPORT3 */
	
#ifdef HASPORT4
	
	pin = pin - 8;

	if (pin <= 7)
	{
		auto unsigned short int result = P4IN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return (LOW);
		}
	}

#endif /* HASPORT4 */

	/* If we get here, the pin was out of range of the device. Return with the pin state as LOW. */
	
	return (LOW);
}

inline void toggle(unsigned short int pin)
{

#ifdef HASPORT1
	
	if (pin <= 7) /* Is pin less than or equal to 7? If yes, then operate on port1 */
	{
		/* Calculate a bitmask by shifting 1 by pin. */

		P1OUT ^= (1 << pin); /* XOR PxOUT with the bitmask, Which toggles the current state of the bit (and pin). */
		return;
	}

#endif /* HASPORT1 */
	
	pin = pin - 8; /* Since pin was higher than 8, subtract by 8 and compare again next block */

	/* The next blocks of code are like the above block */

#ifdef HASPORT2
	
	if (pin <= 7)
	{
		P2OUT ^= (1 << pin);
		return;
	}

#endif /* HASPORT2 */
	
	pin = pin - 8;

#ifdef HASPORT3
	
	if (pin <= 7)
	{
		P3OUT ^= (1 << pin);
		return;
	}

#endif /* HASPORT3 */
	
#ifdef HASPORT4
	
	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT ^= (1 << pin);
	}

#endif /* HASPORT4 */
	
	return;
}

inline void setPullUp(unsigned short int pin)
{

#ifdef HASPORT1

	if (pin <= 7)
	{
		P1REN |= (1 << pin);
		P1OUT |= (1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef HASPORT2

	if (pin <= 7)
	{
		P2REN |= (1 << pin);
		P2OUT |= (1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef HASPORT3

	if (pin <= 7)
	{
		P3REN |= (1 << pin);
		P3OUT |= (1 << pin);
		return;
	}

#endif

#ifdef HASPORT4

	pin = pin - 8;

	if (pin <= 7)
	{
		P4REN |= (1 << pin);
		P4OUT |= (1 << pin);
	}

#endif

	return;
}

inline void setPullDown(unsigned short int pin)
{

#ifdef HASPORT1

	if (pin <= 7)
	{
		P1REN |= (1 << pin);
		P1OUT &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef HASPORT2

	if (pin <= 7)
	{
		P2REN |= (1 << pin);
		P2OUT &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef HASPORT3

	if (pin <= 7)
	{
		P3REN |= (1 << pin);
		P3OUT &= ~(1 << pin);
		return;
	}

#endif

#ifdef HASPORT4

	pin = pin - 8;

	if (pin <= 7)
	{
		P4REN |= (1 << pin);
		P4OUT &= ~(1 << pin);
	}

#endif

	return;
}

inline void setPullOff(unsigned short int pin)
{

#ifdef HASPORT1

	if (pin <= 7)
	{
		P1REN &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef HASPORT2

	if (pin <= 7)
	{
		P2REN &= ~(1 << pin);
		return;
	}

#endif

	pin = pin - 8;

#ifdef HASPORT3

	if (pin <= 7)
	{
		P3REN &= ~(1 << pin);
		return;
	}

#endif

#ifdef HASPORT4

	pin = pin - 8;

	if (pin <= 7)
	{
		P4REN &= ~(1 << pin);
	}

#endif

	return;
}

inline void attachInterrupt(unsigned short int pin, unsigned short int edge, void (*function)())
{
	if (pin <= 7)
	{

		if (edge == HIGH_TO_LOW)
		{
			P1IES |= (1 << pin);
		}
		else if (edge == LOW_TO_HIGH)
		{
			P1IES &= ~(1 << pin);
		}
		else
		{
			return;
		}

		Port1FunctionVector[pin] = function;

		P1IFG &= ~(1 << pin);
		P1IE |= (1 << pin);

		return;
	}
	else
	{
		pin = pin - 8;

		if (pin <= 7)
		{
			if (edge == HIGH_TO_LOW)
			{
				P2IES |= (1 << pin);
			}
			else if (edge == LOW_TO_HIGH)
			{
				P2IES &= ~(1 << pin);
			}
			else
			{
				return;
			}

			Port2FunctionVector[pin] = function;

			P2IFG &= ~(1 << pin);
			P2IE |= (1 << pin);

			return;
		}
	}

	return;
}

inline void removeInterrupt(unsigned short int pin)
{
	if (pin <= 7) //If pin is less or equal to 7, then we need to operate on Port1
	{
		P1IE &= ~(1 << pin); //Clear Interrupt Enable flag
		
		return;//Exit
	}
	else //Check again if pin is less or equal to 7
	{
		pin = pin - 8; //Offset pin by 8.

		if (pin <= 7)//If pin is less than or equal to 7, then we need to operate on Port2
		{
			P2IE &= ~(1 << pin); //Clear Interrupt Enable Flag
			
			return;//Exit
		}

		return; //If pin does not match anything above, then return. 
	}
}

#pragma INTERRUPT (port1_isr);
#pragma vector=PORT1_VECTOR //Port 1 Interrupt Service Routine.
static interrupt void port1_isr(void)
{

	auto unsigned short int result;
	auto unsigned short int count_num = 0; //Dec. version of count.
	auto unsigned short int count = 0x01;//Bitwise version of count.
	
	do
	{
		result = P1IFG & count;
		count_num++;
		count = count << 1;
	}
	while (result == 0 || count != 0x80); //Exit the loop if the result is not false or if count_num is over 8.
	
	if (result == 0)//If count_num is over 8, then there isn't a pin to service.
	{
		//If we get here, Who the hell called this ISR? No P1IFG interrupt flags were set.
		return;//Exit ISR
	}
	else //We found a pin to service
	{
		(*Port1FunctionVector[count_num])(); //Call a function in array. No offset is needed since this is Port 1.
		P2IFG &= ~count;//Clear the interrupt flag in P1IFG.

		return;//Exit ISR
	}
}

#pragma INTERRUPT (port2_isr);
#pragma vector=PORT2_VECTOR //Port2 Interrupt Service Routine.
static interrupt void port2_isr(void)
{

	auto unsigned short int result;
	auto unsigned short int count_num = 0; //Dec. version of count.
	auto unsigned short int count = 0x01;//Bitwise version of count.
	
	do//Attempt to find a interrupted pin on P2IFG.
	{
		result = P2IFG & count;
		count_num++;
		count = count << 1;
	}
	while (result == 0 || count != 0x80); //Exit the loop if the result is not false or if count_num is over 8.
	
	if (result == 0)//If count_num is over 8, then there isn't a pin to service.
	{
		//If we get here, Who the hell called this ISR? No P2IFG interrupt flags were set.
		return;//Exit ISR
	}
	else //We found a pin to service.
	{
		(*Port2FunctionVector[count_num])(); //Call a function in a array. Since this is Port2, We need to add a offset to the array index.
		P2IFG &= ~count;//Clear the interrupt flag bit.

		return;//Exit the ISR.
	}

}

#endif /* End 2 series function block */

/* Begin 5 Series functions */
#if SERIES == 5

inline void setHigh(unsigned short int pin)
{

#ifdef HASPORTA
	
	if (pin <= 15)
	{
		PAOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTB
	
	if (pin <= 15)
	{
		PBOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTC
	
	if (pin <= 15)
	{

		PCOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTD
	
	if (pin <= 15)
	{
		PDOUT |= (1 << pin);

		return;
	}
#endif
	
	pin = pin - 16;

#ifdef HASPORTE
	
	if (pin <= 15)
	{

		PEOUT |= (1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTF
	
	if (pin <= 15)
	{

		PFOUT |= (1 << pin);

		return;
	}

#endif
	
#ifdef HASPORTJ
	
	if (pin <= 15)
	{

		PJOUT |= (1 << pin);

		return;
	}

#endif
	
	return; /* Seems like the pin number was out of range, so just return */
}

inline void setLow(unsigned short int pin)
{

#ifdef HASPORTA
	
	if (pin <= 15)
	{

		PAOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTB
	
	if (pin <= 15)
	{

		PBOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTC
	
	if (pin <= 15)
	{
		PCOUT &= ~(1 << pin);

		return;
	}

#endif

	pin = pin - 16;

#ifdef HASPORTD
	
	if (pin <= 15)
	{
		PDOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTE
	
	if (pin <= 15)
	{

		PEOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTF
	
	if (pin <= 15)
	{

		PFOUT &= ~(1 << pin);

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTJ
	
	if (pin <= 15)
	{

		PJOUT &= ~(1 << pin);

		return;
	}

#endif
	
	return; /* Seems like the pin number was out of range, so just return. Also somewhat pointless if this function is inlined... */
}

inline void pinMode(unsigned short int pin, unsigned short int state)
{
	/* Function flow

	 This function first checks state by checking if it is higher than 1.

	 0 - Which would be INPUT
	 1 - Which would be OUTPUT

	 */

	if (state > OUTPUT)
	{
		return;
	}

#ifdef HASPORTA
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PADIR |= (1 << pin);
		}
		else
		{
			PADIR &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTA */
	
	pin = pin - 16;

#ifdef HASPORTB
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PBDIR |= (1 << pin);
		}
		else
		{
			PBDIR &= ~(1 << pin);
		}

		return;
	}

#endif /*HASPORTB*/
	
	pin = pin - 16;

#ifdef HASPORTC
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PCDIR |= (1 << pin);
		}
		else
		{
			PCDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTD
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PDDIR |= (1 << pin);
		}
		else
		{
			PDDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTE
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PEDIR |= (1 << pin);
		}
		else
		{
			PEDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
	pin = pin - 16;

#ifdef HASPORTF
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PFDIR |= (1 << pin);
		}
		else
		{
			PFDIR &= ~(1 << pin);
		}

		return;
	}

#endif
	
#ifdef HASPORTJ
	
	if (pin <= 15)
	{
		if (state == OUTPUT)
		{
			PJDIR |= (1 << pin);
		}
		else
		{
			PJDIR &= ~(1 << pin);
		}
	}
#endif
	
	return;
}

inline void togglePin(unsigned short int pin)
{

#ifdef HASPORTA

	if (pin <= 15)
	{
		PAOUT ^= (1 << pin);
		return;
	}

#endif /* HASPORTA */

	pin = pin - 16;

#ifdef HASPORTB

	if (pin <= 15)
	{
		PBOUT ^= (1 << pin);
		return;
	}

#endif /* HASPORTB */

	pin = pin - 16;

#ifdef HASPORTC

	if (pin <= 15)
	{
		PCOUT ^= (1 << pin);
		return;
	}

#endif /* HASPORTC */

	pin = pin - 16;

#ifdef HASPORTD

	if (pin <= 15)
	{
		PDOUT ^= (1 << pin);
		return;
	}

#endif /* HASPORTD */

	pin = pin - 16;

#ifdef HASPORTE

	if (pin <= 15)
	{
		PEOUT ^= (1 << pin);
		return;
	}

#endif /* HASPORTE */

	pin = pin - 16;

#ifdef HASPORTF

	if (pin <= 15)
	{
		PFOUT ^= (1 << pin)
				return;
	}

#endif /* HASPORTF */

	pin = pin - 16;

#ifdef HASPORTJ

	if (pin <= 15)
	{
		PJOUT ^= (1 << pin);

	}

#endif /* HASPORTJ */

	return;
}

inline bool readPin(unsigned short int pin)
{
#ifdef HASPORTA

	if (pin <= 15)
	{
		auto unsigned short int result = PAIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* HASPORTA */
	
	pin = pin - 16;

#ifdef HASPORTB
	
	if (pin <= 15)
	{
		auto unsigned short int result = PBIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /*HASPORTB*/
	
	pin = pin - 16;

#ifdef HASPORTC
	
	if (pin <= 15)
	{
		auto unsigned short int result = PCIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* HASPORTC */
	
	pin = pin - 16;

#ifdef HASPORTD

	if (pin <= 15)
	{
		auto unsigned short int result = PDIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* HASPORTD */
	
	pin = pin - 16;

#ifdef HASPORTE

	if (pin <= 15)
	{
		auto unsigned short int result = PEIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* HASPORTE */
	
	pin = pin - 16;

#ifdef HASPORTF
	
	if (pin <= 15)
	{
		auto unsigned short int result = PFIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* HASPORTF */
	
	pin = pin - 16;

#ifdef HASPORTJ

	if (pin <= 15)
	{
		auto unsigned short int result = PJIN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif /* HASPORTJ */
	
	return (LOW);
}

inline void setDriveStrength(unsigned short int pin, unsigned short int level)
{
	if (level > 1)
	{
		return;
	}

#ifdef HASPORTA
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PADS |= (1 << pin);
		}
		else
		{
			PADS &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTA */
	
	pin = pin - 16;

#ifdef HASPORTB
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PBDS |= (1 << pin);
		}
		else
		{
			PBDS &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTB */

	pin = pin - 16;

#ifdef HASPORTC

	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PCDS |= (1 << pin);
		}
		else
		{
			PCDS &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTC */
	
	pin = pin - 16;

#ifdef HASPORTD

	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PDDS |= (1 << pin);
		}
		else
		{
			PDDS &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTD */
	
	pin = pin - 16;

#ifdef HASPORTE
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PEDS |= (1 << pin);
		}
		else
		{
			PEDS &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTE */
	
	pin = pin - 16;

#ifdef HASPORTF
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PFDS |= (1 << pin);
		}
		else
		{
			PFDS &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTF */
	
	pin = pin - 16;

#ifdef HASPORTJ
	
	if (pin <= 15)
	{
		if (level == HIGH)
		{
			PJDS |= (1 << pin);
		}
		else
		{
			PJDS &= ~(1 << pin);
		}

		return;
	}

#endif /* HASPORTJ */
	
	return;
}

inline void setPullUp(unsigned short int pin)
{
#ifdef HASPORTA

	if (pin <= 15)
	{
		PAREN |= (1 << pin);
		PAOUT |= (1 << pin);
		return;
	}

#endif /* HASPORTA */

	pin = pin - 16;

#ifdef HASPORTB

	if (pin <= 15)
	{
		PBREN |= (1 << pin);
		PBOUT |= (1 << pin);
		return;
	}

#endif /* HASPORTB */

	pin = pin - 16;

#ifdef HASPORTC

	if (pin <= 15)
	{
		PCREN |= (1 << pin);
		PCOUT |= (1 << pin);
		return;
	}

#endif /* HASPORTC */

	pin = pin - 16;

#ifdef HASPORTD

	if (pin <= 15)
	{
		PDREN |= (1 << pin);
		PDOUT |= (1 << pin);
		return;
	}

#endif /* HASPORTD */

	pin = pin - 16;

#ifdef HASPORTE

	if (pin <= 15)
	{
		PEREN |= (1 << pin);
		PEOUT |= (1 << pin);
		return;
	}

#endif /* HASPORTE */

	pin = pin - 16;

#ifdef HASPORTF

	if (pin <= 15)
	{
		PFREN |= (1 << pin);
		PFOUT |= (1 << pin);
		return;
	}

#endif /* HASPORTF */

#ifdef HASPORTJ

	pin = pin - 16;

	if (pin <= 15)
	{
		PJREN |= (1 << pin);
		PJOUT |= (1 << pin);
	}

#endif /* HASPORTJ */

	return;

}

inline void setPullDown(unsigned short int pin)
{
#ifdef HASPORTA

	if (pin <= 15)
	{
		PAREN |= (1 << pin);
		PAOUT &= ~(1 << pin);
		return;
	}

#endif /* HASPORTA */

	pin = pin - 16;

#ifdef HASPORTB

	if (pin <= 15)
	{
		PBREN |= (1 << pin);
		PBOUT &= ~(1 << pin);
		return;
	}

#endif /* HASPORTB */

	pin = pin - 16;

#ifdef HASPORTC

	if (pin <= 15)
	{
		PCREN |= (1 << pin);
		PCOUT &= ~(1 << pin);
		return;
	}

#endif /* HASPORTC */

	pin = pin - 16;

#ifdef HASPORTD

	if (pin <= 15)
	{
		PDREN |= (1 << pin);
		PDOUT &= ~(1 << pin);
		return;
	}

#endif /* HASPORTD */

	pin = pin - 16;

#ifdef HASPORTE

	if (pin <= 15)
	{
		PEREN |= (1 << pin);
		PEOUT &= ~(1 << pin);
		return;
	}

#endif /* HASPORTE */

	pin = pin - 16;

#ifdef HASPORTF

	if (pin <= 15)
	{
		PFREN |= (1 << pin);
		PFOUT &= ~(1 << pin);
		return;
	}

#endif /* HASPORTF */

#ifdef HASPORTJ

	pin = pin - 16;

	if (pin <= 15)
	{
		PJREN |= (1 << pin);
		PJOUT &= ~(1 << pin);
	}

#endif /* HASPORTJ */

	return;
}

inline void setPullOff(unsigned short int pin)
{
#ifdef HASPORTA

	if (pin <= 15)
	{
		PAREN &= ~(1 << pin);
		return;
	}

#endif /* HASPORTA */

	pin = pin - 16;

#ifdef HASPORTB

	if (pin <= 15)
	{
		PBREN &= ~(1 << pin);
		return;
	}

#endif /* HASPORTB */

	pin = pin - 16;

#ifdef HASPORTC

	if (pin <= 15)
	{
		PCREN &= ~(1 << pin);
		return;
	}

#endif /* HASPORTC */

	pin = pin - 16;

#ifdef HASPORTD

	if (pin <= 15)
	{
		PDREN &= ~(1 << pin);
		return;
	}

#endif /* HASPORTD */

	pin = pin - 16;

#ifdef HASPORTE

	if (pin <= 15)
	{
		PEREN &= ~(1 << pin);
		return;
	}

#endif /*  HASPORTE */

	pin = pin - 16;

#ifdef HASPORTF

	if (pin <= 15)
	{
		PFREN &= ~(1 << pin);
		return;
	}

#endif /* HASPORTF */

#ifdef HASPORTJ

	pin = pin - 16;

	if (pin <= 15)
	{
		PJREN &= ~(1 << pin);
	}

#endif /* HASPORTJ */

	return;
}

inline void attachInterrupt(unsigned short int pin, unsigned short int edge, void (*function)())
{
	if (pin <= 7)
	{

		if (edge == HIGH_TO_LOW)
		{
			P1IES |= (1 << pin);
		}
		else if (edge == LOW_TO_HIGH)
		{
			P1IES &= ~(1 << pin);
		}
		else
		{
			return;
		}

		Port1FunctionVector[pin] = function;

		P1IFG &= ~(1 << pin);
		P1IE |= (1 << pin);

		return;
	}
	else
	{
		pin = pin - 8;

		if (pin <= 7)
		{
			if (edge == HIGH_TO_LOW)
			{
				P2IES |= (1 << pin);
			}
			else if (edge == LOW_TO_HIGH)
			{
				P2IES &= ~(1 << pin);
			}
			else
			{
				return;
			}

			Port2FunctionVector[pin] = function;

			P2IFG &= ~(1 << pin);
			P2IE |= (1 << pin);

			return;
		}
	}

	return;
}

inline void removeInterrupt(unsigned short int pin)
{
	if (pin <= 7) //If pin is less or equal to 7, then we need to operate on Port1
	{
		P1IE &= ~(1 << pin); //Clear Interrupt Enable flag

		return;//Exit
	}
	else //Check again if pin is less or equal to 7
	{
		pin = pin - 8; //Offset pin by 8.

		if (pin <= 7)//If pin is less than or equal to 7, then we need to operate on Port2
		{
			P2IE &= ~(1 << pin); //Clear Interrupt Enable Flag

			return;//Exit
		}

		return; //If pin does not match anything above, then return.
	}
}

#pragma INTERRUPT (port1_isr);
#pragma vector=PORT1_VECTOR
static interrupt void port1_isr(void)
{
	switch ( P1IV )
	{
		case 0:
			break;

		case 2:
			(*Port1FunctionVector[0])();
			break;

		case 4:
			(*Port1FunctionVector[1])();
			break;

		case 6:
			(*Port1FunctionVector[2])();
			break;

		case 8:
			(*Port1FunctionVector[3])();
			break;

		case 10:
			(*Port1FunctionVector[4])();
			break;

		case 12:
			(*Port1FunctionVector[5])();
			break;

		case 14:
			(*Port1FunctionVector[6])();
			break;

		case 16:
			(*Port1FunctionVector[7])();
			break;

		default:
			_never_executed();

	}
}

#pragma INTERRUPT (port2_isr);
#pragma vector=PORT2_VECTOR
static interrupt void port2_isr(void)
{
	switch ( P2IV )
	{
		case 0:
			break;

		case 2:
			(*Port2FunctionVector[0])();
			break;

		case 4:
			(*Port2FunctionVector[1])();
			break;

		case 6:
			(*Port2FunctionVector[2])();
			break;

		case 8:
			(*Port2FunctionVector[3])();
			break;

		case 10:
			(*Port2FunctionVector[4])();
			break;

		case 12:
			(*Port2FunctionVector[5])();
			break;

		case 14:
			(*Port2FunctionVector[6])();
			break;

		case 16:
			(*Port2FunctionVector[7])();
			break;

		default:
			_never_executed();
	}

}

#endif

#else /* IO_H not defined. */
#error "Fatal error. Source file (io.c) included before header file (io.h)"
#endif /* IO_H */
