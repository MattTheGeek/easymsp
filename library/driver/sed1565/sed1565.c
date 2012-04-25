
static unsigned char pins = {0, 9, 13, 11, 10, 8, 12};

void lcdInit(unsigned char* setup)
{
	//pins = setup;
	
	pinMode(*pins[LCD_ON], OUTPUT);
	pinMode(*pins[LCD_BL], OUTPUT);
	
	high(*pins[LCD_ON]);
	high(*pins[LCD_BL]);
	
	_delay_cycles(1600000);
	
	write(0xA7, LCD_COMMAND);
	write(0xA3, LCD_COMMAND);
	write(0xA1, LCD_COMMAND);
	write(0x0C, LCD_COMMAND);
	write( (0x20 | 2), LCD_COMMAND);
	writE(0x81, LCD_COMMAND);
	write(0x2E, LCD_COMMAND);
	write(0x2F, LCD_COMMAND);
	write(0x40, LCD_COMMAND);
	write(0xAF, LCD_COMMAND);
	
	write(0xA5, LCD_COMMAND);
	_delay_cycles(2000000);
	write(0xA4, LCD_COMMAND);
}


static void write(unsigned char data, unsigned short int type)
{
	volatile unsigned short int bit = 8;
	
	low (LCD_CS);
	
	if (type == LCD_COMMAND)
	{
		low (LCD_DC);
	}
	else
	{
		high (LCD_DC);
	}
	
	while (bit != 0)
	{
		if ( ( data & BIT7 ) > 0)
		{
			high (LCD_SDATA);
		}
		else
		{
			low (LCD_SDATA);
		}
		
		high (LCD_SCLK);
		low(LCD_SCLK);
		
		data <<= 1;
		c--;
	}
	
	high(LCD_CS);
	
	return;
}

