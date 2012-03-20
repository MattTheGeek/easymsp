/*
 * System.c
 *
 *
 *
 */



inline void enterAM(void)
{
	asm("	bic.w	 #0xF0,	0(SP)");
	return;
}

inline void enterLPM0(void)
{
	asm("	bis.w	#0x10,	SR");
	return;
}

inline void enterLPM1(void)
{
	asm("	bis.w	#0x50,	SR");
	return;
}

inline void enterLPM2(void)
{
	asm("	bis.w	#0x90,	SR");
	return;
}

inline void enterLPM3(void)
{
	asm("	bis.w	#0xD0,	SR");
	return;
}

inline void enterLPM4(void)
{
	asm("	bis.w	#0xF0,	SR");
	return;
}

inline void reset(void)
{
	WDTCTL = 0; //Cause a PUC
}

inline void shutdown(void)
{
	enterLPM4();
}

inline unsigned short int swapByte(unsigned short int data)
{
	_swap_bytes(unsigned short data);
	return(data);
}

void inline delaySec(register unsigned short int time)
{
	while (time != 0)
	{
		delayms(1);
		time--;
	}
}

void inline delayms(register unsigned short int time)
{
	while (time != 0)
	{
		delayus(50);
		time--;
	}
}

void inline delayus(register unsigned short int time)
{
	while (time != 0)
	{
		_delay_cycles(16);
		time--;
	}
}

/* cleanup */
void shiftOut(unsigned short int DOUT, unsigned short int SCLK,
		unsigned short int bitorder, unsigned char data)
{
	auto unsigned char bits = 8;
	auto unsigned char value = 0;
	
	while (bits != 0)
	{
		if (bitorder == MSBFIRST)
		{
			value = data & 0x80;
		}
		else
		{
			value = data & 0x01;
		}

		setHigh(SCLK);
		
		if (value > 0)
		{
			setHigh(DOUT);
		}
		else
		{
			setLow(DOUT);
		}

		setLow(SCLK);
		
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

unsigned char shiftIn(unsigned short int DIN, unsigned short int SCLK,
		unsigned short int bitorder)
/* confirm: Test shiftIn() */
{
	auto unsigned short int bits = 8;
	auto unsigned short int data = 0;
	
	while (bits != 0)
	{
		setHigh(SCLK);
		_delay_cycles(1000); //Allow the data to change

		if (readPin(DIN) == true)
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

		setLow(SCLK);
		
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
	
	return ((unsigned char) data);
	
}

void serialOut(unsigned short int pin, unsigned short int baud,
		unsigned char data)
/// \attention correct bit timing has not been calculated. you will need to calculate the bit timings yourself OR wait until they are calculated in the next release.
/// \todo calculate correct bit times.
/// \remarks Other than calculating correct bit times, serialOut() seems to generate serial perfectly.
{
	//Start
	setLow(pin);
	delayus(baud);
	
	auto unsigned short int bits = 8;
	
	while (bits != 0)
	{
		auto unsigned short int result = data & 0x80;
		
		if (result > 0)
		{
			setHigh(pin);
		}
		else
		{
			setLow(pin);
		}

		delayus(baud);
		
		data = data << 1;
		bits--;
	}

	//Stop
	setHigh(pin);
	delayus(baud);
}

