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
	
	return;
}


void pinMode(unsigned short int pin, unsigned short int state)
{
	if (pin <= 7)
	{
		if (state == OUTPUT)
		{
			P1DIR |= (1 << pin);
		}
		else if (state == INPUT)
		{
			P1DIR &= ~(1 << pin);
		}
		else
		{
			return;
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
		else if (state == INPUT)
		{
			P2DIR &= ~(1 << pin);
		}
		else
		{
			return;
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
			else if (state == INPUT)
			{
				P3DIR &= ~(1 << pin);
			}
			else
			{
				return;
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
