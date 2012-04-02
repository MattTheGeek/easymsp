unsigned short int spiConfig(unsigned short int module, unsigned short int bitorder, unsigned short int clockpol, unsigned short int clockphase)
{
	if(module == UCB)
	{
		UCB0CTL1 = UCSWRST;
	}
	else
	{
		UCA0CTL1 = UCSWRST;
	}
	
	if(bitorder == MSBFIRST)
	{
		if(module == UCB)
		{
			UCB0CTL0 |= UCMSB; //Set UCB0 to MSBFIRST
		}
		else
		{
			UCA0CTL0 |= UCMSB; //Set UCA0 to MSBFIRST
		}
	}
	else
	{
		if(module == UCB)
		{
			UCB0CTL0 &= ~UCMSB; //Set UCB0 to LSBFIRST
		}
		else
		{
			UCA0CTL0 &= ~UCMSB; //Set UCA0 to LSBFIRST
		}
	}
	
	if(clockpol == HIGH) 
	{
		if(module == UCB)
		{
			UCB0CTL0 |= UCCKPL; //Set UCB0 to HIGH inactive state
		}
		else
		{
			UCA0CTL0 |= UCCKPL; //Set UCA0 to HIGH inactive state
		}
	}
	else
	{
		if(module == UCB)
		{
			UCB0CTL0 &= ~UCCKPL; //Set UCB0 to LOW inactive state
		}
		else
		{
			UCA0CTL0 &= ~UCCKPL;
		}
	}
	
	if(clockphase == RISING_EDGE)
	{
		if(module == UCB)
		{
			UCB0CTL0 |= UCCKPH; //Set UCB0 to capture on the rising edge and send on the falling
		}
		else
		{
			UCA0CTL0 |= UCCKPH;
		}
	}
	else
	{
		if(module == UCB)
		{
			UCB0CTL0 &= ~UCCKPH; //Set UCB0 to send on the rising edge and capture on the falling
		}
		else
		{
			UCA0CTL0 &= ~UCCKPH;
		}
	}
	
	if(module == UCB)
	{
		UCB0CTL0 |=	UCMODE_0 | UCMST; //Set UCB as 3 Wire SPI and as Master.
	}
	else
	{	UCA0CTL0 |= UCMODE_0 | UCMST;
	
	}
	
	#ifndef SPI_7BIT
		if (module == UCB)
		{
			UCB0CTL0 &= ~UC7BIT;
		}
		else
		{
			UCA0CTL0 &= ~UC7BIT;
		}
	#else
		if(module == UCB)
		{
			UCB0CTL0 |= UC7BIT;
		}
		else
		{
			UCA0CTL0 |= UC7BIT;
		}
	#endif
	
	if(module == UCB)
	{
		UCB0CTL1 |= UCSSEL_3;
	}
	else
	{
		UCA0CTL1 |= UCSSEL_3;
	}
	
	//Do other setup
	if (module == UCB)
	{
		UCB0BR0 = 0;
		UCB0BR1 = 0;
	}
	else
	{
		UCA0BR0 = 0;
		UCA0BR1 = 0;
	}
	
	if(module == UCB)
	{
		UCB0CTL1 &= ~UCSWRST;
	}
	else
	{
		UCA0CTL1 &= ~UCSWRST;
	}
	
	return(0);
}

void spiSetSpeed(unsigned short int module, unsigned short int speed)
{
	if(module == UCB)
	{
		UCB0BR0 = speed;
		UCB0BR1 = speed >> 8;
		return;
	}
	else
	{
		UCA0BR0 = speed;
		UCA0BR1 = speed >> 8;
		return;
	}
}
	
void spiOut(unsigned short int module, unsigned char c)
{
	if(module == UCB)
	{
		while((UCB0STAT & UCBUSY) > 0)
		{
		}
		
		UCB0TXBUF = c;
		return;
	}
	else
	{
		while((UCA0STAT & UCBUSY) > 0)
		{
		}
		
		UCA0TXBUF = c;
		return;
	}
}

void spiString(unsigned short int module, char* string)
{


}

unsigned char spiIn(unsigned short int module)
{
	if (module == UCB)
	{
		while((UCB0STAT & UCBUSY) > 0)
		{
		}
	
		return(UCB0RXBUF);
	}
	else
	{
		while((UCA0STAT & UCBUSY) > 0)
		{
		}
		
		return(UCA0RXBUF);
	}
}

void usciOff(unsigned short int module)
{
	if(module == UCB)
	{
		UCB0CTL1 = UCSWRST;
		return;
	}
	else
	{
		UCA0CTL1 = UCSWRST;
		return;
	}
}
