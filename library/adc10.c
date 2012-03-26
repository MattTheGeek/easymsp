#if SERIES == 2

unsigned short int analogRead(unsigned short int pin)
{
	//Ok, we need to setup the ADC10.
	
	ADC10CTL1 &= ~INCH_15; //Clear the channel select.
   
	switch(pin)
	{
		case 0:
			ADC10CTL1 |= INCH_0;
			break;
 
 		case 1:
  			ADC10CTL1 |= INCH_1;
			break;
  
	  	case 2:
  			ADC10CTL1 |= INCH_2;
			break;
  
  		case 3:
  			ADC10CTL1 |= INCH_3;
			break;
  
 		case 4:
  			ADC10CTL1 |= INCH_4;
			break;
  
  		case 5:
 			ADC10CTL1 |= INCH_5;
			break;
  
		case 6:
  			ADC10CTL1 |= INCH_6;
			break;
  
		case 7:
 			ADC10CTL1 |= INCH_7;
			break;
  
 	 	case 0xFF:
 	 		ADC10CTL1 |= INCH_10;
			break;
   
  		default:
 			return(0);
	}
   
	if (lowPowerMode == true) //Did the user enable low power mode
	{
		ADC10CTL0 |= ADC10SR; // enable for low power mode
	}
	else
	{
		ADC10CTL0 &= ~ADC10SR;	//clear for low power mode
	}
   
	if (pin != 0xFF)
	{
		ADC10AE0 = (1 << pin); //Shift until we get the desired bitmask, so we can enable analog on that pin
	}
  
	//ADC10CTL1 |= ISSH;
   
	ADC10CTL0 |= ADC10ON | ENC | ADC10SC; // Enable the ADC10, Enable conversion and then start sampling.
	
	while ((ADC10CTL1 & ADC10BUSY) > 0) //Wait until the conversion is over
	{
	}
	
	ADC10AE0 = 0; 
   
	ADC10CTL0 &= ~(ADC10ON | ENC | ADC10SC);
   
	return (ADC10MEM); //Return the value.
}

void analogReference(unsigned short int ref)
{

	ADC10CTL0 &= ~SREF_7; //Clear the past reference setting.
	
	switch (ref)
	{
		case DEFAULT:
		
			/* Not required as the reference is cleared before hand.
				ADC10CTL0 &= ~SREF_7; //Clear the register
				ADC10CTL0 |= SREF_0;
			*/
			break;
	
		case INTERNAL:
	
			/* Not required as the reference is cleared before hand.
				ADC10CTL0 &= ~SREF_7; //Clear the register
				ADC10CTL0 |= SREF_0;
			*/
			break;
	
		case INTERNAL1V5:
	
			/* Not required as the reference is cleared before hand.
				ADC10CTL0 &= ~SREF_7; //Clear the register
			*/
			
			ADC10CTL0 |= SREF_1 | REFON;
			ADC10CTL0 &= ~REF2_5V;
			break;
	
		case INTERNAL2V56:
		
			/* Not required as the reference is cleared before hand.
				ADC10CTL0 &= ~SREF_7; //Clear the register
			*/
			
			ADC10CTL0 |= SREF_1 | REFON | REF2_5V;
			break;
	
		case EXTERNAL:
		
			/* Not required as the reference is cleared before hand.
				ADC10CTL0 &= ~SREF_7; //Clear the register
			*/
			
			ADC10CTL0 |= SREF_2;
			break;
		
		default:
			break;
	}
	
	return;
}

void analogConfig(unsigned short int holdtime, unsigned short int format, unsigned short int invert)
{

	ADC10CTL0 &= ~ADC10SHT_3; //Clear sample hold time
	
	switch (holdtime)
	{
		case 4:
			/* Not needed as it is cleared before hand.
				ADC10CTL0 &= ~ADC10SHT_3; //4 Clocks
			*/
			break;
		
		case 8:
			ADC10CTL0 |= ADC10SHT_1; //8 clocks
			break;
		
		case 16:
			ADC10CTL0 |= ADC10SHT_2; //16 Clocks
			break;
		
		case 64:
			ADC10CTL0 |= ADC10SHT_3; //64 Clocks
			break;
		
		default:
			break;
	}
	
	if (format == TWOCOMP)
	{
		ADC10CTL1 |= ADC10DF;
	}
	else
	{
		ADC10CTL1 &= ~ADC10DF;
	}
	
	if (invert == INVERTED)
	{
		ADC10CTL1 |= ISSH;
	}
	else
	{
		ADC10CTL1 &= ~ISSH;
	}
	
	return;
}

#endif /* SERIES 2*/

#if SERIES == 5

unsigned char analogReadByte(unsigned short int pin)
{

	/*
		todo: Need to find a way to get bytewide results.
	*/

	return (NULL);

}

#endif /* SERIES 5 */

