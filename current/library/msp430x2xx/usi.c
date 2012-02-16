void spiConfig(unsigned short int mode, unsigned short int bitorder, unsigned short int clockphase, unsigned short int clockpol)
{
	USICTL0 = USISWRST;
	
	USICTL0 |= USIMST; //Master mode
	
	switch (mode)
	{
		case SPI3WIRE:
			USICTL0 |= USIPE7 | USIPE6 | USIPE6;
			break;
		
		case SPI_INPUT_ONLY:
			USICTL0 |= USIPE7 | USIPE5;
			break;
		
		case SPI_OUTPUT_ONLY:
			USICTL0 |= USIPE6 | USIPE5;
			break;
		
		default:
			USICTL0 |= USIPE7 | USIPE6 | USIPE5;
			break;
	}
	
	if (bitorder == LSBFIRST)
	{
		USICTL0 |= USILSB;
	}
	else
	{
		USICTL0 &= ~USILSB;
	}
	
	USICTL1 = NULL;
	
	if (clockphase == RISING_EDGE)
	{
		USICTL1 |= USICKPH;
	}
	else
	{
		USICTL1 &= ~USICKPH;
	}
	
	USICKCTL = USISSEL_3;
	
	if (USICKPL == HIGH)
	{
		USICKCTL |= USICKPL;
	}

	USICTL0 &= ~USISWRST;
	
	return;
}

void spiSetSpeed(unsigned short int divider)
{
	USICKCTL &= ~USIDIV_7;

	switch (divider)
	{
		case 1:
			//Noting, as the divisor setting would be 000
			break;
		
		case 2:
			USICKCTL |= USIDIV_1;
			break;
		
		case 4:
			USICKCTL |= USIDIV_2;
			break;
		
		case 8:
			USICKCTL |= USIDIV_3;
			break;
		
		case 16:
			USICKCTL |= USIDIV_4;
			break;
		
		case 32:
			USICKCTL |= USIDIV_5;
			break;
		
		case 64:
			USICKCTL |= USIDIV_6;
			break;
	
		case 128:
			USICKCTL |= USIDIV_7;
			break;
		
		default:
			break;
	}
	
	return;
}

void spiOut(unsigned char data)
{
	
	while((USICNT & BIT0+BIT1+BIT2+BIT3+BIT4) > 0)
	{
	}

	USISRL = data;
	USICNT |= 8;
	USICTL0 |= USIOE;
}

unsigned char spiIn(void)
{
	USICNT |= 8;
	
	while((USICNT & BIT0+BIT1+BIT2+BIT3+BIT4) > 0)
	{
	}
	
	return(USISRL);
}

void usiOff(void)
{
	USICTL0 = USISWRST;
	return;
}
