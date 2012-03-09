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

inline void high(unsigned short int pin)
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

inline void low(unsigned short int pin)
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