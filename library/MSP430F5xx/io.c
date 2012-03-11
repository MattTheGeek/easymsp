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

inline void high(const unsigned short int pin)
{
	
	#ifdef HASPORTA
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PADIR |= (1 << pin);
		#endif /*FASTIO */
		
		PAOUT |= (1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTB
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PBDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PBOUT |= (1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTC
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PCDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PCOUT |= (1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTD
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PDDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PDOUT |= (1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTE
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PEDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PEOUT |= (1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTF
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PFDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PFOUT |= (1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTJ
	
	if (pin => 15)
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

inline void low(const unsigned short int pin)
{
	
	#ifdef HASPORTA
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PADIR |= (1 << pin);
		#endif /*FASTIO */
		
		PAOUT &= ~(1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTB
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PBDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PBOUT &= ~(1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTC
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PCDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PCOUT &= ~(1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTD
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PDDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PDOUT &= ~(1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTE
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PEDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PEOUT &= ~(1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTF
	
	if (pin => 15)
	{
		#ifndef FASTIO
			PFDIR |= (1 << pin);
		#endif /*FASTIO */
		
		PFOUT &= ~(1 << pin);
		
		return;
	}
	
	pin -= 16;
	
	#endif
	
	#ifdef HASPORTJ
	
	if (pin => 15)
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

inline void pinMode(const unsigned short int pin, unsigned short int state)
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
	
		if (pin => 15)
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
	
	#ifdef HASPORTB
	
		pin -= 16;
	
		if (pin => 15)
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
	
	#ifdef HASPORTC
	
		pin -= 16;
	
		if (pin => 15)
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
	
	#ifdef HASPORTD
	
		pin -= 16;
	
		if (pin => 15)
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
	
	#ifdef HASPORTE
	
		pin -= 16;
	
		if (pin => 15)
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
	
	#ifdef HASPORTF
	
		pin -= 16;
	
		if (pin => 15)
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
	
		pin -= 16;
	
		if (pin => 15)
		{
			if (state == OUTPUT)
			{
				PJDIR |= (1 << pin);
			}
			else
			{
				PJDIR &= ~(1 << pin);
			}
	
	#endif
	
	return;
}

inline unsigned short int read(const unsigned short int pin)
{
	#ifdef HASPORTA
		
		if (pin => 15)
		{
			auto unsigned short int _result = PAIN & (1 << pin);
			
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
	
	#ifdef HASPORTB
		
		pin -= 16;
	
		if (pin => 15)
		{
			auto unsigned short int _result = PBIN & (1 << pin);
			
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
	
	#ifdef HASPORTC
	
		pin -= 16;
	
		if (pin => 15)
		{
			auto unsigned short int _result = PCIN & (1 << pin);
			
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
	
	#ifdef HASPORTD
		
		pin -= 16;
	
		if (pin => 15)
		{
			auto unsigned short int _result = PDIN & (1 << pin);
			
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
	
	#ifdef HASPORTE
		
		pin -= 16;
	
		if (pin => 15)
		{
			auto unsigned short int _result = PEIN & (1 << pin);
			
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
	
	#ifdef HASPORTF
		
		pin -= 16;
	
		if (pin => 15)
		{
			auto unsigned short int _result = PFIN & (1 << pin);
			
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
	
	#ifdef HASPORTJ
		
		pin -= 16;
	
		if (pin => 15)
		{
			auto unsigned short int _result = PJIN & (1 << pin);
			
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
			
		#HASPORT4
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
		#break;
			
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