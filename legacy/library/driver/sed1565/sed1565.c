static short int (*pins)[7];

static const unsigned char lcdInitCommands[11] =
{
	0xA7,
	0xA3,
	0xA1,
	0x0C,
	(0x20 | 2),
	0x81,
	0x2E,
	0x2F,
	0x40,
	0xAF,
	0xA5,
};

void lcdInit(const unsigned short int* setup)
{
	register volatile unsigned short int count = 0;

	pins = setup;

	do
	{
		pinMode( (*pins)[count], OUTPUT);
		count++;
	}
	while (count != 7);

	/* The above do while loop replaces the below code.
	 *
	 *	pinMode(*pins[sedPins.CS], OUTPUT);
	 *	pinMode(*pins[sedPins.DC], OUTPUT);
	 *	pinMode(*pins[sedPins.SDAT], OUTPUT);
	 *	pinMode(*pins[sedPins.SCLK], OUTPUT);
	 *	pinMode(*pins[sedPins.RST], OUTPUT);
	 *	pinMode(*pins[sedPins.PWR], OUTPUT);
	 *	pinMode(*pins[sedPins.BL], OUTPUT);
	 */

	setHigh( (*pins)[_PWR] );
	setHigh( (*pins)[_BL] );

	delayCycles(1600000);

	lcdSetup();

	//write(0xA5, LCD_COMMAND);
	//_delay_cycles(2000000);
	//write(0xA4, LCD_COMMAND);
}

static void lcdSetup(void)
{
	register volatile unsigned short int count = 0;
	
	setLow( (*pins)[_RST] );
	delayCycles(1000);
	setHigh( (*pins)[_RST] );

	do
	{
		write(lcdInitCommands[count], _COMMAND);
		count++;
	}
	while (count != sizeof lcdInitCommands + 1);


/*
		write(0xA7, _COMMAND);
		write(0xA3, _COMMAND);
		write(0xA1, _COMMAND);
		write(0x0C, _COMMAND);
		write( (0x20 | 2), _COMMAND);
		writE(0x81, _COMMAND);
		write(0x2E, _COMMAND);
		write(0x2F, _COMMAND);
		write(0x40, _COMMAND);
		write(0xAF, _COMMAND);
		*/
}

extern inline void lcdBackLight(unsigned short int state)
{
	if (state == ON)
	{
		setLow( (*pins)[_BL] );
	}
	else if (state == OFF)
	{
		setHigh( (*pins)[_BL] );
	}
	else
	{
		return;
	}
}

extern inline void lcdClear(void)
{
	lcdSetup();
}


static void write(unsigned char data, const unsigned short int type)
{
	if(type == _COMMAND)
	{
		setLow( (*pins)[_DC] );
	}
	else if (type == _DATA)
	{
		setHigh( (*pins)[_DC]) ;
	}
	else
	{
		return;
	}

	setLow( (*pins)[_CS] );

	shiftOut( (*pins)[_SDAT], (*pins)[_SCLK], data);

	setHigh( (*pins)[_CS] );

	return;
}

extern inline void lcdCommand(unsigned char data)
{
	write(data, _COMMAND);
}


