/*

	softi2c.c

*/

unsigned short int i2cWrite(unsigned char address, unsigned char data) 
{
	volatile unsigned char count;
	
	setLow(_SDA); /* Issue Start */
	
	for(count = 7; count > 0; count--) /* Send address */
	{
		setLow(_SCL);
		
		if ((address & (bitmaskLookup[count])) > 0)
		{
			setHigh(_SDA);
		}
		else
		{
			setLow(_SDA);
		}
		
		setHigh(_SCL);
	}
		setLow(_SCL);
		setHigh(_SCL);
		
		setLow(_SDA); /* Set the R/W bit as write */
		
		setLow(_SCL);
		setHigh(_SDA);
		pinMode(_SDA, INPUT);
		
		if (pinRead(_SDA))
		{
			return (TIMEOUT);
		}
		
		pinMode(_SDA, OUTPUT);
		
	for(count = 8; count > 0; count--)
	{
		setLow(_SCL);
		
		if ((data & (bitmaskLookup[count])) > 0)
		{
			setHigh(_SDA);
		}
		else
		{
			setLow(_SDA);
		}
		
		setHigh(_SCL);
	}
	
	setLow(_SCL);
	pinMode(_SDA, INPUT);
	setHigh(_SCL);
	
	if (pinRead(_SDA))
	{
			return (TIMEOUT);
	}
	
	setLow(_SCL);
	setLow(_SDA);
	setHigh(_SCL);
	setHigh(_SDA);
	
	return (0);
}
