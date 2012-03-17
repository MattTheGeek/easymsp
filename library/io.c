/**
 * Just some quick notes...
 *
 * I wanted IO operations to be as fast possible, but still keep some safety measures.
 * So when ever you attempt to turn on a IO pin, the functiona will clear the pin select registers for that pin alone.
 * You can disable this by defining FASTIO.
 *
 * Another measure EasyMSP does is sets the direction register for that pin no matter what.
 *
 * EasyMSP will also check if the pin is out of range, and handles it.
 *
 *
 *
 */

#if SERIES == 2
/* For 8 BIT ports */

void high(unsigned short int pin)
{
	if(pin <= 7)
	{
		#ifndef FASTIO
		
			P1SEL &= ~(1 << pin);
			P1SEL2 &= ~(1 << pin);
			
		#endif

		P1OUT |= (1 << pin);

		#ifndef FASTIO

			P1DIR |= (1 << pin);

		#endif

		return;
	}

	pin = pin - 8;

	if(pin <= 7)
	{
		#ifndef FASTIO
		
			P2SEL &= ~(1 << pin);
			P2SEL2 &= ~(1 << pin);
			
		#endif

		P2OUT |= (1 << pin);

		#ifndef FASTIO

			P2DIR |= (1 << pin);

		#endif

		return;
	}
	
	#ifdef HASPORT3
	
	pin = pin - 8;

	if(pin <= 7)
	{
		#ifndef FASTIO
		
			P3SEL &= ~(1 << pin);
			P3SEL2 &= ~(1 << pin);
			
		#endif

		P3OUT |= (1 << pin);

		#ifndef FASTIO

			P3DIR |= (1 << pin);

		#endif

		return;
	}
	
	#endif
	
	#ifdef HASPORT4
		
		pin = pin - 8;
		
		if (pin <= 7)
		{
			#ifndef FASTIO
				P4SEL &= ~(1 << pin);
				P4SEL2 &= ~(1 << pin);
			#endif
			
			P4OUT |= (1 << pin);
			
			#ifndef FASTIO

				P4DIR |= (1 << pin);

			#endif
		}
		
	#endif
	
	return;
}

void high_z(unsigned short int pin)
{
	if (pin <= 7)
	{
		P1DIR &= ~(1 << pin);
		P1OUT |= (1 << pin);
		return;
	}
	
	pin = pin - 8;
	
	if (pin <= 7)
	{
		P2DIR &= ~(1 << pin);
		P2OUT |= (1 << pin);
		return;
	}
	
	#ifdef HASPORT3
			
		pin = pin - 8;
			
		if (pin <= 7)
		{
			P3DIR &= ~(1 << pin);
			P3OUT |= (1 << pin);
			return;
		}
		
	#endif
		
	return;
}


void low(unsigned short int pin)
{
	if(pin <= 7)
	{
		#ifndef FASTIO
		
			P1SEL &= ~(1 << pin);
			P1SEL2 &= ~(1 << pin);
			
		#endif

		P1OUT &= ~(1 << pin);

		#ifndef FASTIO

			P1DIR |= (1 << pin);

		#endif

		return;
	}

	pin = pin - 8;

	if(pin <= 7)
	{
		#ifndef FASTIO
		
			P2SEL &= ~(1 << pin);
			P2SEL2 &= ~(1 << pin);
			
		#endif

		P2OUT &= ~(1 << pin);

		#ifndef FASTIO

			P2DIR |= (1 << pin);

		#endif

		return;
	}
	
	#ifdef HASPORT3
	
	pin = pin - 8;

	if(pin <= 7)
	{
		#ifndef FASTIO
		
			P3SEL &= ~(1 << pin);
			P3SEL2 &= ~(1 << pin);
			
		#endif

		P3OUT &= ~(1 << pin);

		#ifndef FASTIO

			P3DIR |= (1 << pin);

		#endif

		return;
	}
	
	#endif
	
	#ifdef HASPORT4
		
		pin = pin - 8;
		
		if (pin <= 7)
		{
			#ifndef FASTIO
				P4SEL &= ~(1 << pin);
				P4SEL2 &= ~(1 << pin);
			#endif
			
			P4OUT |= (1 << pin);
			
			#ifndef FASTIO

				P4DIR &= ~(1 << pin);

			#endif
		}
		
	#endif
	
	return;
}


void pinMode(unsigned short int pin, unsigned short int state)
{
	
	if (state > 1)
	{
		return;
	}
	
	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P1DIR |= (1 << pin);
		}
		else
		{
			P1DIR &= ~(1 << pin);
		}
		
		return;
	}

	pin = pin - 8;

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

	#ifdef HASPORT3
	
		pin = pin - 8;
		
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

	#endif
	
	#ifdef HASPORT4
		
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
		
	#endif
		
	return;
}


/* DEPRECATED!
 *
 * Please use pinMode() instead.
 *
 * void input(unsigned short int pin)
 * {
 *	if(pin <= 7)
 *	{
 *		#ifndef FASTIO
 *
 *			P1SEL &= ~(1 << pin);
 *			P1SEL2 &= ~(1 << pin);
 *
 *		#endif
 *
 *		P1DIR &= ~(1 << pin);
 *
 *		#ifndef FASTIO
 *
 *			P1OUT &= ~(1 << pin);
 *
 *		#endif
 *
 *		return;
 *	}
 *
 *	pin = pin - 8;
 *
 *	if(pin <= 7)
 *	{
 *		#ifndef FASTIO
 *
 *			P2SEL &= ~(1 << pin);
 *			P2SEL2 &= ~(1 << pin);
 *
 *		#endif
 *
 *		P2DIR &= ~(1 << pin);
 *
 *		#ifndef FASTIO
 *
 *			P2OUT &= ~(1 << pin);
 *
 *		#endif
 *
 *		return;
 *	}
 *	#ifdef HASPORT3
 *
 *	pin = pin - 8;
 *
 *	if(pin <= 7)
 *	{
 *		#ifndef FASTIO
 *
 *			P3SEL &= ~(1 << pin);
 *			P3SEL2 &= ~(1 << pin);
 *
 *		#endif
 *
 *		P3DIR &= ~(1 << pin);
 *
 *		#ifndef FASTIO
 *
 *			P3OUT &= ~(1 << pin);
 *
 *		#endif
 *
 *		return;
 *	}
 *
 *	#endif
 *
 *	return;
 * }
 *
 * void output(unsigned short int pin)
 * {
 *	if(pin <= 7)
 *	{
 *		#ifndef FASTIO
 *
 *			P1SEL &= ~(1 << pin);
 *			P1SEL2 &= ~(1 << pin);
 *
 *		#endif
 *
 *
 *		P1OUT &= ~(1 << pin);
 *		P1DIR |= (1 << pin);
 *		return;
 *	}
 *
 *	pin = pin - 8;
 *
 *	if(pin <= 7)
 *	{
 * 		#ifndef FASTIO
 *
 *			P2SEL &= ~(1 << pin);
 *			P2SEL2 &= ~(1 << pin);
 *
 *		#endif
 *
 *		P2OUT &= ~(1 << pin);
 *		P2DIR |= (1 << pin);
 *		return;
 *	}
 *
 *	#ifdef HASPORT3
 *
 *	pin = pin - 8;
 *
 *	if(pin <= 7)
 *	{
 *		#ifndef FASTIO
 *
 *			P3SEL &= ~(1 << pin);
 *			P3SEL2 &= ~(1 << pin);
 *
 *		#endif
 *
 *		P3OUT &= ~(1 << pin);
 *		P3DIR |= (1 << pin);
 *		return;
 *	}
 *
 *	#endif
 *
 *	return;
 * }
 *
 */

bool read(unsigned short int pin)
{
	if(pin <= 7)
	{
		#ifndef FASTIO
			P1SEL &= ~(1 << pin);
			P1SEL2 &= ~(1 << pin);
		#endif

		P1DIR &= ~(1 << pin);
		P1OUT &= ~(1 << pin);

		auto unsigned short int result = P1IN & (1 << pin);

		if(result > 0)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}

	pin = pin - 8;

	if(pin <= 7)
	{
		#ifndef FASTIO
		
			P2SEL &= ~(1 << pin);
			P2SEL2 &= ~(1 << pin);
			
		#endif

		P2DIR &= ~(1 << pin);
		P2OUT &= ~(1 << pin);

		auto unsigned short int result = P2IN & (1 << pin);

		if(result > 0)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
	
	#ifdef HASPORT3
	
	pin = pin - 8;

	if(pin <= 7)
	{
		#ifndef FASTIO
			P3SEL &= ~(1 << pin);
			P3SEL2 &= ~(1 << pin);
		#endif

		P3DIR &= ~(1 << pin);
		P3OUT &= ~(1 << pin);

		auto unsigned short int result = P3IN & (1 << pin);

		if(result > 0)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
	
	#endif

	return (false);
}

void portWrite(unsigned short int port, unsigned short int data)
{
	switch (port)
	{
		case PORT1:
			P1OUT = data;
			return;

		case PORT2:
			P2OUT = data;
			return;

		#ifdef HASPORT3
		
			case PORT3:
				P3OUT = data;
				return;
				
		#endif

		default:
			return;
	}
}

void portDirection(unsigned short int port, unsigned short int data)
{
	switch (port)
	{
		case PORT1:
			P1DIR = data;
			return;

		case PORT2:
			P2DIR = data;
			return;

		#ifdef HASPORT3
		
			case PORT3:
				P3DIR = data;
				return;
				
		#endif

		default:
			return;
	}
}

unsigned char portRead(unsigned short int port)
{
    switch (port)
    {
        case PORT1:
            return (P1IN);

        case PORT2:
            return (P2IN);

        #ifdef HASPORT3

            case PORT3:
                return (P3IN);
				
        #endif

        default:
            return(0);
    }
}

void toggle(unsigned short int pin)
{
    if (pin <= 7)
    {
        P1OUT ^= (1 << pin);
        return;
    }

    pin = pin - 8;

    if (pin <= 7)
    {
        P2OUT ^= (1 << pin);
        return;
    }

    #ifdef HASPORT3

        pin = pin - 8;

        if (pin <= 7)
        {
            P3OUT ^= (1 << pin);
            return;
        }

    #endif

    return;
}

void enableResistor(unsigned short int pin, unsigned short int state)
{
	if (pin <= 7)
	{
		if (state == PULLUP)
		{
			P1OUT |= (1 << pin);
		}
		else if (state == PULLDOWN)
		{
			P1OUT &= ~(1 << pin);
		}
		else
		{
			return;
		}

		P1REN |= (1 << pin);

		return;
	}

	pin = pin - 8;

	if (pin <= 7)
	{
		if (state == PULLUP)
		{
			P2OUT |= (1 << pin);
		}
		else if (state == PULLDOWN)
		{
			P2OUT &= ~(1 << pin);
		}
		else
		{
			return;
		}

		P2REN |= (1 << pin);

		return;
	}

	#ifdef HASPORT3

		pin = pin - 8;

		if (pin <= 7)
		{
			if (state == PULLUP)
			{
				P3OUT |= (1 << pin);
			}
			else if (state == PULLDOWN)
			{
				P3OUT &= ~(1 << pin);
			}
			else
			{
				return;
			}

			P3REN |= (1 << pin);

			return;
		}

	#endif

	return;
}

void disableResistor(unsigned short int pin)
{
	if (pin <= 7)
	{
		P1OUT &= ~(1 << pin);
		P1REN &= ~(1 << pin);

		return;
	}

	pin = pin - 8;

	if (pin <= 7)
	{
		P2OUT &= ~(1 << pin);
		P2REN &= ~(1 << pin);

		return;
	}

	#ifdef HASPORT3

		pin = pin - 8;

		if (pin <= 7)
		{
			P3OUT &= ~(1 << pin);
			P3REN &= ~(1 << pin);

			return;
		}

	#endif

	return;
}

#ifndef NO_PORT_ISR

void attachInterrupt(unsigned short int pin, unsigned short int edge, void (*function)())
{
	if (pin <= 7)
	{

		if (edge == HIGH_TO_LOW)
		{
			P1IES |= (1 << pin);
		}
		else
		{
			P1IES &= ~(1 << pin);
		}

		PortFunctionVector[pin] = function;
		
		P1IE |= (1 << pin);

		return;
	}
	else
	{
		pin = pin - 8;

		if(pin <= 7)
		{
			if (edge == HIGH_TO_LOW)
			{
				P2IES |= (1 << pin);
			}
			else
			{
				P2IES &= ~(1 << pin);
			}

			PortFunctionVector[pin + 8] = function;

			P2IE |= (1 << pin);

			return;
		}
	}

		return;
}


void removeInterrupt(unsigned short int pin)
{
	if (pin <= 7) //If pin is less or equal to 7, then we need to operate on Port1
	{
		P1IE &= ~(1 << pin); //Clear Interrupt Enable flag
		
		return; //Exit
	}
	else //Check again if pin is less or equal to 7
	{
		pin = pin - 8; //Offset pin by 8.

		if (pin <= 7) //If pin is less than or equal to 7, then we need to operate on Port2 
		{
			P2IE &= ~(1 << pin); //Clear Interrupt Enable Flag
			
			return; //Exit
		}
		
		return; //If pin does not match anything above, then return. 
	}
}

#pragma vector=PORT1_VECTOR //Port 1 Interrupt Service Routine.
static __interrupt void port1_isr(void)
{

	auto unsigned short int result; 
	auto unsigned short int count_num = 0; //Dec. version of count.
	auto unsigned short int count = 0x01; //Bitwise version of count.
	
	do
	{
		result = P1IFG & count;
		count_num++;
		count = count << 1;
	} 
	while (result == 0 || count != 0x80); //Exit the loop if the result is not false or if count_num is over 8.
	
	if (result == 0) //If count_num is over 8, then there isn't a pin to service.
	{
		//If we get here, Who the hell called this ISR? No P1IFG interrupt flags were set.
		return; //Exit ISR
	}
	else //We found a pin to service
	{
		(*PortFunctionVector[count_num])(); //Call a function in array. No offset is needed since this is Port 1.
		P2IFG &= ~count; //Clear the interrupt flag in P1IFG.
			
		return; //Exit ISR
	}
}

#pragma vector=PORT2_VECTOR //Port2 Interrupt Service Routine.
static __interrupt void port2_isr(void)
{
	
	auto unsigned short int result; 
	auto unsigned short int count_num = 0; //Dec. version of count.
	auto unsigned short int count = 0x01; //Bitwise version of count.
	
	do //Attempt to find a interrupted pin on P2IFG.
	{
		result = P2IFG & count;
		count_num++;
		count = count << 1;
	} 
	while (result == 0 || count != 0x80); //Exit the loop if the result is not false or if count_num is over 8.
	
	if (result == 0) //If count_num is over 8, then there isn't a pin to service.
	{
		//If we get here, Who the hell called this ISR? No P2IFG interrupt flags were set.
		return; //Exit ISR
	}
	else //We found a pin to service.
	{
		(*PortFunctionVector[count_num + 7])(); //Call a function in a array. Since this is Port2, We need to add a offset to the array index.
		P2IFG &= ~count; //Clear the interrupt flag bit.
			
		return; //Exit the ISR.
	}

}

#endif

#endif

#if SERIES == 5

/*
	io.c	Version 1.0A
	IO System Library for 16-bit IO port modules.
		
	Part of the EasyMSP system
	
	This file is under GPL v3
	Copyright Matthew Burmeister 2012. All Rights Reserved.
	
*/

/* 
	Changes
		Added more functions.
		
*/

/* Notes

	Fixed values
		The pin values are fixed to help the compiler optimize the function into a 3 words. However, state arguments found in pinMode(), etc... are NOT constant.
	
*/

inline void high(unsigned short int pin)
{
	
	#ifdef HASPORTA
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PADIR |= (1 << pin);
		#endif /*FASTIO */
		
		PAOUT |= (1 << pin);
		
		return;
	}
	
	#endif

	pin = pin - 16;
	
	#ifdef HASPORTB
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PBDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PBOUT |= (1 << pin);
		
		return;
	}
	
	#endif

	pin = pin - 16;
	
	#ifdef HASPORTC
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PCDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PCOUT |= (1 << pin);
		
		return;
	}
	
	#endif

	pin = pin - 16;
	

	#ifdef HASPORTD
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PDDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PDOUT |= (1 << pin);
		
		return;
	}
	#endif
	
	pin = pin - 16;
	
	#ifdef HASPORTE
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PEDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PEOUT |= (1 << pin);
		
		return;
	}
	
	#endif

	pin = pin - 16;
	
	#ifdef HASPORTF
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PFDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PFOUT |= (1 << pin);
		
		return;
	}
	
	#endif

	//pin = pin - 16;
	
	#ifdef HASPORTJ
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PJDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PJOUT |= (1 << pin);
		
		return;
	}
	
	#endif
	
	return; /* Seems like the pin number was out of range, so just return */
}

inline void low(unsigned short int pin)
{
	
	#ifdef HASPORTA
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PADIR |= (1 << pin);
		#endif /*FASTIO */
		
		PAOUT &= ~(1 << pin);
		
		return;
	}

	#endif
	
	pin = pin - 16;
	
	#ifdef HASPORTB
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PBDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PBOUT &= ~(1 << pin);
		
		return;
	}
	
	#endif

	pin = pin - 16;
	
	#ifdef HASPORTC
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PCDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PCOUT &= ~(1 << pin);
		
		return;
	}

	#endif

	pin = pin - 16;
	
	#ifdef HASPORTD
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PDDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PDOUT &= ~(1 << pin);
		
		return;
	}
	
	#endif

	pin = pin - 16;
	
	#ifdef HASPORTE
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PEDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PEOUT &= ~(1 << pin);
		
		return;
	}
	
	#endif
	
	pin = pin - 16;

	#ifdef HASPORTF
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PFDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PFOUT &= ~(1 << pin);
		
		return;
	}
	
	#endif

	pin = pin - 16;
	
	#ifdef HASPORTJ
	
	if (pin <= 15)
	{
		#ifndef FASTIO
			PJDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PJOUT &= ~(1 << pin);
		
		return;
	}
	
	#endif
	
	return; /* Seems like the pin number was out of range, so just return. Also somewhat pointless if this function is inlined... */
}

inline void digitalWrite(unsigned short int pin, unsigned short int state)
{
	if (state == HIGH)
	{
		high(pin);
	}
	else if (state == LOW)
	{
		low(pin);
	}
	else
	{
		return;
	}
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
	
	//pin = pin - 16;

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

inline bool read(unsigned short int pin)
{
	#ifdef HASPORTA
		
		if (pin <= 15)
		{
			auto unsigned short int result = PAIN & (1 << pin);
			
			if (result > 0)
			{
				return(LOW);
			}
			else
			{
				return(HIGH);
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
				return(LOW);
			}
			else
			{
				return(HIGH);
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
				return(LOW);
			}
			else
			{
				return(HIGH);
			}
		}
		
	#endif
	
	pin = pin - 16;

	#ifdef HASPORTD
		
		if (pin <= 15)
		{
			auto unsigned short int result = PDIN & (1 << pin);
			
			if (result > 0)
			{
				return(LOW);
			}
			else
			{
				return(HIGH);
			}
		}
		
	#endif
	
	pin = pin - 16;

	#ifdef HASPORTE
		
		if (pin <= 15)
		{
			auto unsigned short int result = PEIN & (1 << pin);
			
			if (result > 0)
			{
				return(LOW);
			}
			else
			{
				return(HIGH);
			}
		}
		
	#endif
	
	pin = pin - 16;

	#ifdef HASPORTF
	
		if (pin <= 15)
		{
			auto unsigned short int result = PFIN & (1 << pin);
			
			if (result > 0)
			{
				return(LOW);
			}
			else
			{
				return(HIGH);
			}
		}
		
	#endif
	
	pin = pin - 16;

	#ifdef HASPORTJ
		
		if (pin <= 15)
		{
			auto unsigned short int result = PJIN & (1 << pin);
			
			if (result > 0)
			{
				return(LOW);
			}
			else
			{
				return(HIGH);
			}
		}
		
	#endif
	
	return (LOW);
}

void portWriteByte(unsigned short int port, unsigned char data)
{

	switch (port)
	{
		#ifdef HASPORT1
			case PORT1:
				P1OUT = data;
			break;
		#endif
		
		#ifdef HASPORT2
			case PORT2:
				P2OUT = data;
			break;
		#endif
		
		#ifdef HASPORT3
			case PORT3:
				P3OUT = data;
			break;
		#endif
			
		#ifdef HASPORT4
			case PORT4:
				P4OUT = data;
			break;
		#endif
		
		#ifdef HASPORT5
			case PORT5:
				P5OUT = data;
			break;
		#endif
			
		#ifdef HASPORT6
			case PORT6:
				P6OUT = data;
			break;
		#endif
			
		#ifdef HASPORT7
			case PORT7:
				P7OUT = data;
			break;
		#endif
			
		#ifdef HASPORT8	
			case PORT8:
				P8OUT = data;
			break;
		#endif
			
		#ifdef HASPORT9
			case PORT9:
				P9OUT = data;
			break;
		#endif
		
		#ifdef HASPORT10
			case PORT10:
				P10OUT = data;
			break;
		#endif
		
		#ifdef HASPORT11
			case PORT11:
				P11OUT = data;
			break;
		#endif
		
		default:
		
		break;
	}
	
	return;
}

#endif
