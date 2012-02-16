static inline void flashLock(void)
{
	unsigned int temp = FCTL3 << 8;
	temp = temp >> 8;
	temp |= LOCK;
	
	FCTL3 = flashKey + temp; //Lock the flash
}

static inline int flashUnlock(unsigned int key)
{
	if (key == KEY)
	{
	
		unsigned int temp = FCTL3 << 8;
		
		temp = temp >> 8;
		temp &= ~LOCK;
		FCTL3 = flashKey + temp; //Key entered correctly, Unlock flash.
		return(1); //Return with success
	}
	else
	{
		return(-1); //Return with failure.
	}
}

static inline int flashReadWord(unsigned int* address)
{
	return(*address);
}

static inline int flashReadByte(unsigned int *address)
{
	return(((*address << 8) >> 8));
}

static int flashWriteWord(unsigned int key, unsigned int address, unsigned int data)
/// \todo Finish Function

{	
	if (key != KEY)
	{
		return(-1);
	}

	disableWD(); //Disable Watchdog if enabled.
	
	unsigned int tempfreq = _currentfreq; 
	
	setCPUFreq(M1); //Set MCLK to 1Mhz
	

	FCTL2 = flashKey + FSSEL_1 + BIT1 + BIT0; //MCLK / 3 = Flash clock
	FCTL1 = flashKey + WRT; //Enable write
	flashUnlock(KEY); //Unlock Flash
	
	// Write data
	
	flashLock(); //Relock flash
	FCTL1 &= flashKey + ~WRT; //Disable write
	
	setCPUFreq(tempfreq);
	
	if ((FCTL3 & flashKey + FAIL) > 0) //Was the write a sucess
	{
		FCTL3 &= flashKey + ~FAIL; //Clear fail flag
		return(-1); //No
	}
	else
	{
		return(1); //Yes
	}
}


static int flashEraseSegment(unsigned int key, unsigned int key2, unsigned int segment)
/// \todo Write function
{
	if(key == KEY && key2 == KEY2)
	{
		//Erase segment
		//To be added
		return(1);
	}
	else
	{
		return(-1);
	}
}

static int flashEraseMainMemory(unsigned int key, unsigned int key2)
/// \todo Write function
{
	if (key != KEY && key2 != KEY2)
	{
		return(-1);
	}
	else
	{
	//To be added
		return(1); //Success
	}
}

static int flashEraseAll(unsigned int key, unsigned int key2)
/// \todo Write function
{	
	if (key != KEY && key2 != KEY2)
	{
		return(-1);
	}
	else
	{
	//To be added
		return(1); //Success
	}
}
