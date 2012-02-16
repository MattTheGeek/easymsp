
void shiftOut(unsigned int DOUT, unsigned int SCLK, unsigned int bitorder, unsigned char data)
{
	register unsigned char bits=8;
	register unsigned char value=0;
	
	while(bits != 0)
	{
		if (bitorder == MSBFIRST)
		{
			value = data & 0x80;
		}
		else
		{
			value = data & 0x01;
		}
		
		high(SCLK);
		
		if (value > 0)
		{
			high(DOUT);
		}
		else
		{
			low(DOUT);
		}
		
		low(SCLK);
		
		if (bitorder == MSBFIRST)
		{
			data = data << 1;
		}
		else
		{
			data = data >> 1;
		}
		
		bits--;
	}
}

unsigned char shiftIn(unsigned int DIN, unsigned int SCLK, unsigned int bitorder)
/// \todo Test shiftIn() 
{
	register unsigned int bit=0;
	register unsigned int clock=0;
	register unsigned char bits=8;
	register unsigned char data=0;
	register unsigned int bit_unvalid_time = 5000;
	
	while (bits != 0)
	{
		clock = read(SCLK);
		
		while (clock == 0)
		{
			if (bit_unvalid_time == 0)
			{
				return (0);
			}
			
			clock = read(SCLK);
			
			bit_unvalid_time--;
		}
		
		bit = read(DIN);
		
		if (bit > 0)
		{
			if (bitorder == MSBFIRST)
			{
				data |= 0x80;
			}
			else
			{
				data |= 0x01;
			}
		}
		else
		{
			if (bitorder == MSBFIRST)
			{
				data |= 0x80;
			}
			else
			{
				data |= 0x01;
			}
		}
		
		if (bitorder == MSBFIRST)
		{
			data = data >> 1;
		}
		else
		{
			data = data << 1;
		}
		
		bits--;
		
		clock = read(SCLK);
		
		while(clock > 0)
		{
			
			if (bit_unvalid_time == 0)
			{
				return (0);
			}
			
			clock = read(SCLK);
			
			bit_unvalid_time--;
		}
		
	}
	
	return (data);
}

void serialOut(unsigned int pin, unsigned int baud, unsigned char data)
/// \attention correct bit timing has not been calculated. you will need to calculate the bit timings yourself OR wait until they are calculated in the next release.
/// \todo calculate correct bit times.
/// \remarks Other than calculating correct bit times, serialOut() seems to generate serial perfectly.
{
	//Start
	low(pin);
	delayus(baud);
	
	unsigned int bits = 8;
	
	while(bits != 0)
	{
		unsigned int result = data & 0x80;
		
		if (result > 0)
		{
			high(pin);
		}
		else
		{
			low(pin);
		}
		
		delayus(baud);
		
		data = data << 1;
		bits--;
	}
	
	//Stop
	high(pin);
	delayus(baud);
}
