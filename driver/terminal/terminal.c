//terminal.c
//Terminal Booster Pack Driver

unsigned int startTerminal(unsigned int font)
{
	#ifdef HASUSI
	//USI mode
	
	#else
		#ifdef HASUSCI
		//USCI mode
		spiConfig(UCB, LSBFIRST, LOW, RISING_EDGE); //Setup proper SPI comm.
		
		//Send init commands to LCD
		
		#else
		//Bitbang
		
		#endif
		
	#endif
}

void putc(char c)
{
	#ifdef HASUSI
	//USI mode
	
	#else
		#ifdef HASUSCI
		//USCI mode
		
		#else
		//Bitbang
		
		#endif
		
	#endif

}

void printf(char* string)
{
	#ifdef HASUSI
	//USI mode
	
	#else
		#ifdef HASUSCI
		//USCI mode
		
		#else
		//Bitbang
		
		#endif
		
	#endif

}

void putp(unsigned int x, unsigned int y)
{
	#ifdef HASUSI
	//USI mode
	
	#else
		#ifdef HASUSCI
		//USCI mode
		
		#else
		//Bitbang
		
		#endif
		
	#endif

}

