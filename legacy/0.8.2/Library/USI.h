//Copyright 2011 Matthew Burmeister
//USI driver

static int hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase);
static void hspiOut(unsigned char);
static unsigned char hspiIn();

static void usiOff(void);

static int hi2cConfig();
static void hi2cOut(unsigned char address, unsigned char data);
static unsigned char hi2cIn(unsigned char address);

static unsigned int usi_clockspeed = FAST;
static unsigned int usi_i2cspeed;
static unsigned int usi_device;

//static void incoming_data_int();

static unsigned char usi_buffer[4];
static unsigned char usi_buffer_index=0;
static unsigned char usi_mode=0;

static int hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase)
{
	USICTL0 = USISWRST; //Reset the USI
	USICTL1 = 0;
	
	USICTL0 |= USIGE; //Output latch always on
	USICTL0 |= USIMST; //Set USI to SPI Master mode
	USICTL0 |= USIPE5; //SCLK Enable
	USICTL0 |= USIPE6; //SDO Enable
	USICTL0 |= USIPE7; //SDI Enable
	
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
		if (clockspeed == SLOW)
		{
			usi_clockspeed = SLOW;
			USICKCTL |= USIDIV_4; // MCLK / 16 = SPI Clk when slow is selected
		}
	}
	else
	{
		usiOff();
		return(-3); //Return with error status -3
	}
	
	USICKCTL |= BIT2;

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
	
	USICTL0 &= ~USISWRST;// Release the USI for operation
	
	return(1);
}

static void hspiOut(unsigned char data)
{
	
	USISRL = data; //Put data into the USI lower shift register
	USICNT = BIT4; //Set bit count to 8
	USICTL0 |= USIOE; //Enable output
	//We delay by x uS to make sure the data gets shifted out
	
	if (usi_clockspeed == FAST)
	{
		delayus(1);
	}
	else
	{
		delayus(16);
	}
	
	USICTL0 &= ~USIOE; //Disable output
	
}

static unsigned char hspiIn()

{	unsigned char status = USICNT & ~0xF0;
	unsigned int invalidbyte = 6000;
	
	while (status != 8 && invalidbyte != 0)
	{
		status = USICNT & ~0xF0;
		invalidbyte--;
	}
	
	USICNT = 0;
	
	return(USISRL);
}
	
static int hi2cConfig(unsigned int device, unsigned int speed) //needs to be cleaned up
{
	
	return(-1);
	
	USICTL0 |= USISWRST; //Reset the USI
	
	USICTL0 |= USIMST; //Set as master
	USICTL0 |= USIPE6;
	USICTL0 |= USIPE7;
	
	USICTL1 |= USII2C; //I2C Mode
	USICTL1 |= USICKPH; //High clock phase
	
	return(1);
	
}

static void hi2cOut(unsigned char address,  unsigned char data)
{
	//Alright. To transmit data we have to make a START signal.
	
	//Transmit Address
	
	//Transmit data
	
	//Now we have to make a STOP Signal
		
}

static unsigned char hi2cIn(unsigned char address)
{
	//Read from buffer
	register unsigned char data = usi_buffer[usi_buffer_index];
	
	usi_buffer_index--;
	
	return(data);
}
	
static void usiOff(void)
{
	USICTL0 = USISWRST;
}

