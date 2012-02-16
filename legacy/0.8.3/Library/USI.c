static int hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase)
{
	USICTL0 = USISWRST; //Reset the USI
	USICTL1 = 0; //Clear USI Control 2
	USICKCTL = 0; //Clear USI Clock Control
	USICNT = 0; //Clear USI Count Control
	
	USICTL0 |= USIPE6 | USIPE5 | USIOE;  //Enable Output, Input and SCLK pins.
	//USICTL0 |= USIGE; //Output latch always on
	USICTL0 |= USIMST; //Set USI to SPI Master mode

	if (bitorder == LSBFIRST || bitorder == MSBFIRST) //Did the user enter correct pramameters?
	{
		if (bitorder == LSBFIRST) //Check for the requested bit order
		{
			USICTL0 |= USILSB; //LSB First
		}
	}
	else //Whoops, user didnt entrr correct parameters.
	{
		usiOff();
		return(-1); //Return with ERROR -1
	}
	
	if (phase == FALLING_EDGE || phase == RISING_EDGE)// did the user enter incorrext settings?
	{
		//Nope they didnt, Configure the clock phase
		if (phase == FALLING_EDGE)
		{
			USICTL1 |= USICKPH; 
		}
	}
	else
	{
		//Whoops lookes like they entered incorrect settings
		usiOff();
		return(-2); // Return with error status -2
	}
	
	if (clockspeed == SLOW || clockspeed == FAST)
	{
		USICKCTL = USISSEL_2;
		
		if (clockspeed == SLOW)
		{
			USICKCTL |= USIDIV_4; // MCLK / 16 = SPI Clk when slow is selected
		}
	}
	else
	{
		usiOff();
		return(-3); //Return with error status -3
	}

	if (pol == HIGH || pol == LOW)
	{
		if (pol == HIGH)
		{
			USICKCTL |= USICKPL;
			USICKCTL |= USISWCLK; 
		}
	}
	else
	{
		usiOff();
		return(-4);
	}
	
	usi_mode = SPI; //Remeber that we are in SPI Mode.
	USICTL0 &= ~USISWRST;// Release the USI for operation
	USICNT = 8; //Load USICNT with 8
	USICTL1 |= USIIE; //Enable interrupts

	
	return(1);
}

static int hspiOut(unsigned char data)
/// \todo Check if SPI is getting transmitted correctly.
/// \attention this function has not be tested enough for release.
{
	if (usi_mode != SPI)
	{
		return(-1); //Someone didn't configure first.
	}
	else
	{
		USICTL0 |= USIOE;
		USISRL = data;
		USICNT = 8;
	}
	
	return(1);
}

static unsigned char hspiIn()
/// \todo Check hspiIn.
/// \attention This function has not been tested.
{
	USICTL0 &= ~USIOE;
	USICNT = 8;
	while(USICNT != 0)
	{}
	return(USISRL);
}
	
static void usiOff(void)
{
	USICTL0 = USISWRST;
}

#pragma vector=USI_VECTOR 
__interrupt void usi_background(void)
{
	USICTL1 &= ~USIIFG;
}
