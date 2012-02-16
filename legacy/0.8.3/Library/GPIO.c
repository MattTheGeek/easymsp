static void high(unsigned int pin)
{
	if (pin <= 7) //Is pin equal or lower to 7?
	{
		pin = bit(pin); //Calculate bitmask
			
		P1DIR |= pin; //OR the bitmask to PORT1 direction register.
		P1OUT |= pin; //OR the same bitmask to PORT1 output register.
	}
	
	if (pin <= 16 && pin >= 8) //Is pin equal or higher than 8 but lower or equal to 16
	{
		pin = bit(pin - 8); //Calculate bitmask, subtract 8 from pin to get a proper bitmask.
		
		P2DIR |= pin; //OR the bitmask to PORT2 direction register
		P2OUT |= pin; //OR the bitmask to PORT2 output register
	}

#ifdef HASPORT3 //Does the device have PORT3?

	if (pin <= 23 && pin >= 17) //Is pin higher or equal to 17, but not higher than 23?
	{
		pin = bit(pin - 16); //Calculate bitmask, subtract 16 from pin to get a proper bitmask
		
		P3DIR |= pin; //OR the bitmask to PORT3 direction register
		P3OUT |= pin; //OR the bitmask to PORT3 output register.
	}

#endif

}


//Low
//----------------------------------------------------
static void low(unsigned int pin)
{
	if (pin <= 7) //Is pin equal or lower than 7?
	{
		pin = bit(pin); //Calculate bitmask
		
		P1DIR |= pin; //OR the bitmask to PORT1 direction register
		P1OUT &= ~pin; //NAND the bitmask to PORT1 output register.
	}
	
	if (pin <= 16 && pin >= 8)
	{
		pin = pin - 8;
		pin = bit(pin);
		
		P2DIR |= pin;
		P2OUT &= ~pin;
	}
	
#ifdef HASPORT3

	if (pin <= 23 && pin >= 17)
	{
		pin = pin - 16;
		pin = bit(pin);
		
		P3DIR |= pin;
		P3OUT &= ~pin;
	}

#endif

}

//output
//----------------------------------------------------------------------------

static void output(unsigned int pin)
{
	if (pin <= 7) //If pin is under 8, Use PORT1
	{
		pin = bit(pin); //Calculate bitmask
		
		P1DIR |= pin; //OR the bitmask to PORT1s direction register.
	}
	
	if (pin <= 16 && pin >= 8) //Is pin higher or equal to eight, but not higher than 16?
	{
		pin = bit(pin - 8); //Calculate bitmask. Subtract 8 from pin to calculate proper bitmask.
		
		P2DIR |= pin; //OR the bitmask to PORT2s direction register.
	}
	
#ifdef HASPORT3 //Does the device have PORT3?

	if (pin <= 23 && pin >= 17) //Is pin higher or equal to 17, but not higher than 23?
	{
		pin = bit(pin - 16); //Calculate bitmask. Subtract 16 from pin to calculate proper bitmask.
		
		P3DIR |= pin; //OR the bitmask to PORT3s direction register
	}

#endif

}

//input
//--------------------------------------------------------------------------------------

static void input(unsigned int pin)
{
	if (pin <= 7) //Is pin equal or less than 7?
	{
		pin = bit(pin); //Calculate bitmask	
		
		P1DIR &= ~pin; //NAND to PORT1 Direction register
	}
	
	if (pin <= 16 && pin >= 8) //Is pin higher or equal to 8 but not higher than 16?
	{	
		pin = bit(pin - 8); //Subtract 8 from pin to get a proper bitmask and Then calculate the bitmask
		
		P2DIR &= ~pin; //NAND to PORT2 Direction register
	}
	
#ifdef HASPORT3 //Does the device have PORT3?

	if (pin <= 23 && pin >= 17)//Is pin higher or equal to 17, but not higher than 23?
	{
		pin = bit(pin - 16); //Subtract 16 from pin to get a proper bitmask, And then calculate bitmask.
		
		P3DIR &= ~pin; //NAND to PORT3 Direction register
	}

#endif

}

//Read
//---------------------------------------------------------------

static unsigned int read(unsigned int pin)
{
	if (pin <= 7) //Lower or equal than 7?
	{
		if (P1IN & bit(pin) > 0) //AND P1IN with bit. If the result is higher than 0, then pin is high.
		{
			return(1); //Return with 1
		}
		else
		{
			return(0); //Return with 0
		}
	}
		
	if (pin <= 16 && pin >= 8) //Higher or equal to 8, but not higher than 16?
	{
	
		if(P2IN & bit(pin - 8) > 0) //AND P2IN with bit subtracted by 8. If the result is higher than 0, then the pin is high.
		{
			return(1); //Return with 1
		}
		else
		{
			return(0); //Return with 0
		}
		
	}
	
#ifdef HASPORT3 //Do we have PORT3?

	
	if (pin <= 23 && pin >= 17) //Higher or equal to 17, but not higher than 23?
	{
		if(P3IN & bit(pin - 16) > 0) //NAND P3IN with bit subtracted by 16. If the result is higher than zero, The pin is high
		{
			return(1); //Return with 1
		}
		else
		{
			return(0); //Return with 0
		}
	}
	#endif
	
	return(0); //Return with nothing.
	
}



static void enableResistor(unsigned int pin)
{
	if (pin <= 7) //Is pin equal or less than 7?
	{
		P1REN |= bit(pin); //Calculate bitmask for pin, Then OR to P1REN, Which enables the built in resistor
	}
	
	if (pin <= 16 && pin >= 8) //Is pin more or equal to eight, but not larger than 16?
	{
		P2REN |= bit(pin - 8); //Subtract 8 from pin, Calculate bitmask, Then OR to P2REN,  Which enables the built in resistor
	}
	
	#ifdef HASPORT3 //Do we have PORT3?
		
		if (pin <= 23 && pin >= 17)  //Is pin more or equal to 17, but not larger than 23?
		{
			P3REN |= bit(pin - 16); //Subtract 16 from pin, Calculate bitmask, Then OR to P3REN, which enables the built in resistor
		}
		
	#endif
}
	
static void disableResistor(unsigned int pin)
{
	if (pin <= 7)
	{
		pin = bit(pin); //calculate bitmask
		
		P1REN &= ~pin;
	}
	
	if (pin <= 16 && pin >= 8)
	{
		pin = pin - 8;
		
		pin = bit(pin);
		
		P2REN &= ~pin;
	}
	
	#ifdef HASPORT3
		
		if (pin <= 23 && pin >= 17)
		{
			pin = pin - 16;
			
			pin = bit(pin);
			
			P3REN &= ~pin;
		}
		
	#endif
}

static inline void pinPullUp(unsigned int pin)
{	
	high(pin); //We take a shortcut to pull up a pin by calling high(). High will set the PxOUT register for us.
}

static inline void pinPullDown(unsigned int pin)
{
	low(pin);//We take a shortcut to pull up a pin by calling low(). low will set the PxOUT register for us.
}

static void pinInterruptEnable(unsigned int pin)
{
	if(pin <= 7)
	{
		P1IE |= bit(pin);
	}
	else
	{
		if(pin > 15)
		{
			goto end;
		}
	
	P2IE |= bit(pin - 8);
	
	}
	
	end:;
}

static void pinInterruptDisable(unsigned int pin)
{
	if(pin <= 7)
	{
		P1IE &= ~bit(pin);
	}
	else
	{
		if (pin > 15)
		{
			goto end;
		}
	
		P2IE &= ~bit(pin - 8);
	}
	
	end:;
}

static unsigned int decodeInterruptedPin(unsigned int port)
{
	unsigned int bitstested = 0x01;
	
	if (port == PORT1 || port == 1)
	{
	
		while(bitstested != 0)
		{
			unsigned int result = P1IFG & bitstested;
			
			if (result > 0)
			{
				unsigned int pin=0;
				
				switch (bitstested)
				{
					case 0x01:
						pin = 0;
					break;
					
					case 0x02:
						pin = 1;
					break;
					
					case 0x04:
						pin = 2;
					break;
					
					case 0x08:
						pin = 3;
					break;
					
					case 0x10:
						pin = 4;
					break;
					
					case 0x20:
						pin = 5;
					break;
					
					case 0x40:
						pin = 6;
					break;
					
					case 0x80:
						pin = 7;
					break;
				}
				
				return(pin);
			}
			
			bitstested = bitstested << 1;
		}
		
		//Well then, Looks like someone hurped derped somewhere...
		return(0);
	}
	else
	{
		bitstested = 0x01;
		
		while(bitstested != 0)
		{
			unsigned int result = P2IFG & bitstested;
			
			if (result > 0)
			{
			
				unsigned int pin=0;
				
				switch (bitstested)
				{
					case 0x01:
						pin = 0;
					break;
					
					case 0x02:
						pin = 1;
					break;
					
					case 0x04:
						pin = 2;
					break;
					
					case 0x08:
						pin = 3;
					break;
					
					case 0x10:
						pin = 4;
					break;
					
					case 0x20:
						pin = 5;
					break;
					
					case 0x40:
						pin = 6;
					break;
					
					case 0x80:
						pin = 7;
					break;
				}
				
				return(pin + 8);
			}
			
			bitstested = bitstested << 1;
		}
		
		//Well then, Looks like someone hurped derped somewhere...
		return(0);
	}
}

static void interruptEdgeSelect(unsigned int pin, unsigned int edge)
{
	if (pin <= 7)
	{
		if (edge == RISING)
		{
			P1IES |= bit(pin);
		}
		else
		{
			P1IES &= ~bit(pin);
		}
	}
	else
	{
		if (pin > 15)
		{
			goto end;
		}
		
		pin = bit(pin - 8);
	
		if (edge == RISING)
		{
			P2IES |= pin;
		}
		else
		{
			P2IES &= ~pin;
		}
	}
	
	end:;
}
