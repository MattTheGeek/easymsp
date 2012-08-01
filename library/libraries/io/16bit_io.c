
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

#ifdef HASPORTJ
	
	if (pin <= 15)
	{

		PJOUT &= ~(1 << pin);

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

inline void pinToggle(unsigned short int pin)
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
		PFOUT ^= (1 << pin);
		return;
	}

#endif /* HASPORTF */

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

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

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

#else

#	warning "EasyMSP: setDriveStrength() is only compatible with 5 Series devices. Unexpected results may occur."

#endif
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

	if (pin <= 15)
	{
		PJREN &= ~(1 << pin);
	}

#endif /* HASPORTJ */

	return;
}

inline void portWriteWord(const unsigned short int port, unsigned short int data)
{

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (port)
	{

#	ifdef HASPORTA

		case PORTA:
			PAOUT = data;
			break;

#	endif /* HASPORTA */

#	ifdef HASPORTB

		case PORTB:
			PBOUT = data;
			break;

#	endif /* HASPORTB */

#	ifdef HASPORTC

		case PORTC:
			PCOUT = data;
			break;

#	endif /* HASPORTC */

#	ifdef HASPORTD

		case PORTD:
			PDOUT = data;
			break;

#	endif /* HASPORTD */

#	ifdef HASPORTE

		case PORTE:
			PEOUT = data;
			break;

#	endif /* HASPORTE */

#	ifdef HASPORTF

		case PORTF:
			PFOUT = data;
			break;

#	endif /* HASPORTF */

#	ifdef HASPORTJ

		case PORTJ:
			PJOUT = data;
			break;

#	endif /* HASPORTJ */

		default:
			_never_executed();

	}

#else
#	warning "EasyMSP: portWriteWord() is only compatible with 5 Series devices. Unexpected results may occur."
#endif
}

inline unsigned short int portReadWord(const unsigned short int port)
{

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (port)
	{

#	ifdef HASPORTA

		case PORTA:
			return (PAIN);

#	endif /* HASPORTA */

#	ifdef HASPORTB

		case PORTB:
			return (PBIN);

#	endif /* HASPORTB */

#	ifdef HASPORTC

		case PORTC:
			return (PCIN);

#	endif /* HASPORTC */

#	ifdef HASPORTD

		case PORTD:
			return (PDIN);

#	endif /* HASPORTD */

#	ifdef HASPORTE

		case PORTE:
			return (PEIN);

#	endif /* HASPORTE */

#	ifdef HASPORTF

		case PORTF:
			return (PFIN);

#	endif /* HASPORTF */

#	ifdef HASPORTJ

		case PORTJ:
			return (PJIN);

#	endif /* HASPORTJ */

		default:
			return (0); /* Would love to use _never_executed() here, but we have to return something */

	}

#else

#	warning "EasyMSP: portReadWord() is only compatible with the F5 and F6 Series devices. Unexpected results may occur."
	return (0);

#endif

}

inline void portWriteDirWord(const unsigned short int port, unsigned short int data)
{

#if (_EM_SERIES == 5) || (_EM_SERIES == 6)

	switch (port)
	{

#	ifdef HASPORTA

		case PORTA:
			PADIR = data;
			break;

#	endif /* HASPORTA */

#	ifdef HASPORTB

		case PORTB:
			PBDIR = data;
			break;

#	endif /* HASPORTB */

#	ifdef HASPORTC

		case PORTC:
			PCDIR = data;
			break;

#	endif /* HASPORTC */

#	ifdef HASPORTD

		case PORTD:
			PDDIR = data;
			break;
#	endif /* HASPORTD */

#	ifdef HASPORTE

		case PORTE:
			PEDIR = data;
			break;

#	endif /* HASPORTE */

#	ifdef HASPORTF

		case PORTF:
			PFDIR = data;
			break;

#	endif /* HASPORTF */

#	ifdef HASPORTJ

		case PORTJ:
			PJDIR = data;
			break;

#	endif /* HASPORTJ */

		default:
			_never_executed();

	}

#else

#	warning "EasyMSP: portWriteDirWord() is only compatible with 5 Series devices. Unexpected results may occur."

#endif
}

inline void attachInterrupt(unsigned short int pin, unsigned short int edge, void (*function)(void))
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

#pragma vector=PORT1_VECTOR
interrupt void port1_isr(void)
{
	switch (__even_in_range(P1IV, P1IV_P1IFG7))
	{
		case P1IV_NONE:
			break;

		case P1IV_P1IFG0:
			(*Port1FunctionVector[0])();
			break;

		case P1IV_P1IFG1:
			(*Port1FunctionVector[1])();
			break;

		case P1IV_P1IFG2:
			(*Port1FunctionVector[2])();
			break;

		case P1IV_P1IFG3:
			(*Port1FunctionVector[3])();
			break;

		case P1IV_P1IFG4:
			(*Port1FunctionVector[4])();
			break;

		case P1IV_P1IFG5:
			(*Port1FunctionVector[5])();
			break;

		case P1IV_P1IFG6:
			(*Port1FunctionVector[6])();
			break;

		case P1IV_P1IFG7:
			(*Port1FunctionVector[7])();
			break;

		default:
			_never_executed();

	}
}

#pragma vector = PORT2_VECTOR
interrupt void port2_isr(void)
{
	switch (__even_in_range(P2IV, P1IV_P1IFG7))
	{
		case P2IV_NONE:
			break;

		case P2IV_P2IFG0:
			(*Port2FunctionVector[0])();
			break;

		case P2IV_P2IFG1:
			(*Port2FunctionVector[1])();
			break;

		case P2IV_P2IFG2:
			(*Port2FunctionVector[2])();
			break;

		case P2IV_P2IFG3:
			(*Port2FunctionVector[3])();
			break;

		case P2IV_P2IFG4:
			(*Port2FunctionVector[4])();
			break;

		case P2IV_P2IFG5:
			(*Port2FunctionVector[5])();
			break;

		case P2IV_P2IFG6:
			(*Port2FunctionVector[6])();
			break;

		case P2IV_P2IFG7:
			(*Port2FunctionVector[7])();
			break;

		default:
			_never_executed();

	}

}
