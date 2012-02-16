//Copyright 2011 Matthew Burmeister
//USI driver

static void hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase);
static void hspiOut(unsigned char);
static unsigned char hspiIn();

static void usiOff(void);

static void hi2cConfig();
static void hi2cOut(unsigned char);
static unsigned char hi2cIn();

//static void incoming_data_int();

//static unsigned char buffer[4];
//static unsigned char buffer_index=0;
//static unsigned char mode=0;

static void hspiConfig(unsigned int bitorder, unsigned int clockspeed, unsigned int pol, unsigned int phase)
{
	USICTL0 = USISWRST; //Reset the USI
	
	USICTL0 |= USIOE; //Enable output
	USICTL0 |= USIGE; //Output latch always on
	USICTL0 |= USIMST; //Set USI to SPI Master mode
	USICTL0 |= USIPE5; //SCLK Enable
	USICTL0 |= USIPE6; //SDO Enable
	USICTL0 |= USIPE7; //SDI Enable
	
	if (bitorder == LSBFIRST)
	{
		USICTL0 |= USILSB; //LSB First
	}
	
	if (phase = FALLING_EDGE)
	{
		USICTL1 |= USICKPH; 
	}
	
	
	if (clockspeed = SLOW)
	{
		USICKCTL |= USIDIV_4; // MCLK / 16 = SPI Clk
	}
	
	USICKCTL |= USISEL_1;
	
	if (USICKPL == HIGH)
	{
		USICKCTL |= USICKPL;
		USICKCTL |= USISWCLK; 
	}
	
	USICTL0 &= ~USISWRST;
}

static void hspiOut(unsigned char data)
{
	
	USISRL = data;
	USICNT = 0x08;
	
	if (CLOCKSPEED == FAST)
	{
		delayus(1);
	}
	else
	{
		delayus(16)
	}
	
}

static unsigned char hspiIn()
{	
	while (status != 8)
	{
		unsigned char status = USICNT & ~0xF0;
	}
	
	USICNT = 0;
	
	return(USISRL);
}
	
static void usiOff(void)
{
	USICTL0 = USISWRST;
}
