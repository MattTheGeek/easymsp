/*
 * io.C
 * Version: 1.0.4
 * Library for accessing ports
 *
 * Author: Matthew Burmeister
 * Copyright Matthew Burmeister 2011 - 2012. All Rights Reserved.
 *
 * Part of the EasyMSP Project.
 *
 */

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

#endif

/* Functions for 2 Series Devices */
#if SERIES == 2

inline void setHigh(unsigned short int pin)
{
#ifdef HASPORT1
	
	if (pin <= 7)
	{
		P1OUT |= (1 << pin);
		return;
	}

#endif
	
	pin = pin - 8;

#ifdef HASPORT2
	
	if (pin <= 7)
	{
		P2OUT |= (1 << pin);
		return;
	}

#endif
	
	pin = pin - 8;

#ifdef HASPORT3
	
	if (pin <= 7)
	{
		P3OUT |= (1 << pin);
		return;
	}

#endif
	
#ifdef HASPORT4
	
	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT |= (1 << pin);
	}

#endif
	
	return;
}

inline void setLow(unsigned short int pin)
{
#ifdef HASPORT1
	
	if (pin <= 7)
	{
		P1OUT &= ~(1 << pin);
		return;
	}

#endif
	
	pin = pin - 8;

#ifdef HASPORT2
	
	if (pin <= 7)
	{
		P2OUT &= ~(1 << pin);
		return;
	}

#endif
	
	pin = pin - 8;

#ifdef HASPORT3
	
	if (pin <= 7)
	{
		P3OUT &= ~(1 << pin);
		return;
	}

#endif
	
#ifdef HASPORT4
	
	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT &= ~(1 << pin);
	}

#endif
	
	return;
}

inline void pinMode(unsigned short int pin, unsigned short int state)
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

inline bool readPin(unsigned short int pin)
{
#ifdef HASPORT1
	
	if (pin <= 7)
	{
		auto unsigned short int result = P1IN & (1 << pin);

		if (result > 0)
		{
			return(HIGH);
		}
		else
		{
			return(LOW);
		}
	}

#endif
	
	pin = pin - 8;

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

#endif
	
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

#endif
	
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

#endif
	
	return (LOW);
}

inline void toggle(unsigned short int pin)
{
#ifdef HASPORT1
	
	if (pin <= 7)
	{
		P1OUT ^= (1 << pin);
		return;
	}

#endif
	
	pin = pin - 8;

#ifdef HASPORT2
	
	if (pin <= 7)
	{
		P2OUT ^= (1 << pin);
		return;
	}

#endif
	
	pin = pin - 8;

#ifdef HASPORT3
	
	if (pin <= 7)
	{
		P3OUT ^= (1 << pin);
		return;
	}

#endif
	
#ifdef HASPORT4
	
	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT ^= (1 << pin);
	}

#endif
	
	return;
}

inline void setPullUp(unsigned short int pin)
{

}

inline void setPullDown(unsigned short int pin)
{

}

inline void setPullOff(unsigned short int pin)
{

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

		Port1FunctionVector[pin] = function;

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

			Port2FunctionVector[pin] = function;

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

#endif

#endif

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

#endif
	
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

#endif
	
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

#endif
	
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

#endif
	
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

#endif
	
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

#endif
	
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

#endif

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

#endif
	
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

#endif
	
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

#endif
	
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

#endif
	
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

#endif
	
	return;
}

inline void setPullUp(unsigned short int pin)
{

}

inline void setPullDown(unsigned short int pin)
{

}

inline void setPullOff(unsigned short int pin)
{

}
#pragma INTERRUPT (port1_isr);
#pragma vector=PORT1_VECTOR
static interrupt void port1_isr(void)
{

}
#pragma INTERRUPT (port2_isr);
#pragma vector=PORT2_VECTOR
static interrupt void port2_isr(void)
{

}

#endif
