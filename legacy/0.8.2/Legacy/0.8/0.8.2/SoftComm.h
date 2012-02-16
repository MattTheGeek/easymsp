/*This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 United States License. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
*/

//Designed, Written and debugged by:
//Matthew Burmeister

//SoftComm

static void shiftOut(unsigned int DOUT, unsigned int SCLK, unsigned int bitorder, char data);
static char shiftIn(unsigned int DIN, unsigned int SCLK, unsigned int bitorder);


static void shiftOut(unsigned int DOUT, unsigned int SCLK, unsigned int bitorder, char data)
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
		low(SCLK);
		
		if (value > 0)
		{
			high(DOUT);
		}
		else
		{
			low(DOUT);
		}
		
		high(SCLK);
		
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

static char shiftIn(unsigned int DIN, unsigned int SCLK, unsigned int bitorder)
{
	unsigned int bit=0;
	unsigned int clock=0;
	unsigned char bits=8;
	unsigned char data=0;
	unsigned int bit_unvalid_time = 5000;
	
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
		