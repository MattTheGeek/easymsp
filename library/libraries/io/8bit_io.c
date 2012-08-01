
inline void setHigh(unsigned short int pin)
{

#ifdef HASPORT1 /* Does the device has PORT1? */
	
	if (pin <= 7) /* If pin is equal or less than 7, then we operate on PORT1 */
	{
		/* We need to generate a bitmask for P1OUT, we do this by shifting 0x01 by pin. This produces a bitmask that for the desired bit and pin. */

		P1OUT |= (1 << pin); /* OR the generated bit mask to PxOUT to set the bit and make the pin high */
		
	}

#endif /* HASPORT1 */
	
	pin = pin - 8; /* Since the value was higher than 8, subtract by 8 and later compare */

	/* The next code blocks are generally the same as above. */

#ifdef HASPORT2 /* Does the device has PORT2? */
	
	if (pin <= 7)
	{
		P2OUT |= (1 << pin);
		
	}

#endif /* HASPORT2 */
	
	pin = pin - 8;

#ifdef HASPORT3 /* Does the device has PORT3? */
	
	if (pin <= 7)
	{
		P3OUT |= (1 << pin);
		
	}

#endif /* HASPORT3 */
	
#ifdef HASPORT4 /* Does the device has PORT4? */

	pin = pin - 8;

	if (pin <= 7)
	{
		P4OUT |= (1 << pin);
	}

#endif /* HASPORT4 */
	
	return;
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

inline void pinToggle(unsigned short int pin)
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

inline void attachInterrupt(unsigned short int pin, unsigned short int edge, void (*function)(void))
{
	if ((unsigned short int)function <= 0x01FF) /* Do not allow a function pointer to reference Peripheral module memory */
	{
		return;
	}

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
			
		}

		return; //If pin does not match anything above, then return. 
	}
}

#pragma INTERRUPT (port1_isr);
#pragma vector=PORT1_VECTOR //Port 1 Interrupt Service Routine.
interrupt void port1_isr(void)
{
	volatile unsigned char count = 0;

	while(count < 8)
	{

		if ( ((P1IFG & (1 << count) ) > 0) && ((P1IE & (1 << count) ) > 0 ))
		{
			(*Port1FunctionVector[count])(); //Call a function in array. No offset is needed since this is Port 1.
			P1IFG &= ~(1 << count);//Clear the interrupt flag in P1IFG.
			break;
		}
		else
		{
			count++;
		}
	}

	return; //Exit ISR
}

#pragma INTERRUPT (port2_isr);
#pragma vector=PORT2_VECTOR //Port2 Interrupt Service Routine.
interrupt void port2_isr(void)
{
	volatile unsigned char count = 0;

	while(count < 8)
	{
		if ( ((P2IFG & (1 << count) ) > 0) && ((P2IE & (1 << count) ) > 0 ))
		{
			(*Port2FunctionVector[count])(); //Call a function in array. No offset is needed since this is Port 1.
			P2IFG &= ~(1 << count);//Clear the interrupt flag in P1IFG.
			break;
		}
		else
		{
			count++;
		}
	}
	return; //Exit ISR
}
