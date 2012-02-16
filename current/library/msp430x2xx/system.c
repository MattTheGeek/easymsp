/*
 * System.c
 *
 *
 *
 */

/*
	DEPRECATED!
	The following functions have been deprecated.
	
	Reasons: Transformed into preprocessor macros.

 
void stopwd(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	return;
}

void enterAM(void)
{
	asm("	bic.w	 #0xF0,	0(SP)");
	return;
}

void enterLPM0(void)
{
	asm("	bis.w	#0x10,	SR");
	return;
}

void enterLPM1(void)
{
	asm("	bis.w	#0x50,	SR");
	return;
}

void enterLPM2(void)
{
	asm("	bis.w	#0x90,	SR");
	return;
}

void enterLPM3(void)
{
	asm("	bis.w	#0xD0,	SR");
	return;
}

void enterLPM4(void)
{
	asm("	bis.w	#0xF0,	SR");
	return;
}

void reset(void)
{
	WDTCTL = 0; //Cause a PUC
}

void shutdown(void)
{
	enterLPM4();
}

	END DEPRECATED LIST
*/

void inline delaySec(register unsigned short int time)
{
	while(time != 0)
	{
		delayms(1);
		time--;
	}
}

void inline delayms(register unsigned short int time)
{
	while(time != 0)
	{
		delayus(50);
		time--;
	}
}

void inline delayus(register unsigned short int time)
{
	while(time != 0)
	{
		_delay_cycles(16);
		time--;
	}
}

/*
unsigned int ramRead(unsigned int location)
{
	if (location > (RAMSIZE / 2))
	{
		return(0);
	}
	
	unsigned int* memoryloc = (0x0200 + location);
	
	return(*memoryloc);
}
*/

unsigned short int ramRead(unsigned short int location)
{
	if(location > RAMSIZE)
	{
		return(0);
	}
	
	auto unsigned short int* memoryloc = (unsigned short int*)0x0200 + location;

	return(*memoryloc);
}

unsigned short int ramCopy(unsigned short int source, unsigned short int dest, unsigned short int count)
{
	if ((source + count) > (RAMSIZE / 2) || (dest + count) > (RAMSIZE / 2))
	{
		return(1);
	}
	
	auto unsigned short int* memsource = (unsigned short int*)0x0200 + source;
	auto unsigned short int* memdest = (unsigned short int*)0x0200 + dest;
	
	while(count != 0)
	{
		*memdest = *memsource;
		
		memdest++;
		memsource++;
		count--;
	}
	
	return(0);
}


void shiftOut(unsigned short int DOUT, unsigned short int SCLK, unsigned short int bitorder, unsigned char data)
{
	auto unsigned char bits=8;
	auto unsigned char value=0;
	
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

unsigned char shiftIn(unsigned short int DIN, unsigned short int SCLK, unsigned short int bitorder)
/// \todo Test shiftIn() 
{
	auto unsigned short int bits = 8;
	auto unsigned short int data = 0;
	
	while (bits != 0)
	{
		high(SCLK);
		_delay_cycles(1000); //Allow the data to change
	
		if (read(DIN) == true)
		{
			if(bitorder == MSBFIRST)
			{
				data |= 0x80;
			}
			else
			{
				data |= 0x01;
			}
		}
		
		low(SCLK);
		
		if(bitorder == MSBFIRST)
		{
			data = data << 1;
		}
		else
		{
			data = data >> 1;
		}
		
		bits--;
	}
	
	return ( (unsigned char)data);
	
}

void serialOut(unsigned short int pin, unsigned short int baud, unsigned char data)
/// \attention correct bit timing has not been calculated. you will need to calculate the bit timings yourself OR wait until they are calculated in the next release.
/// \todo calculate correct bit times.
/// \remarks Other than calculating correct bit times, serialOut() seems to generate serial perfectly.
{
	//Start
	low(pin);
	delayus(baud);
	
	auto unsigned short int bits = 8;
	
	while(bits != 0)
	{
		auto unsigned short int result = data & 0x80;
		
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

