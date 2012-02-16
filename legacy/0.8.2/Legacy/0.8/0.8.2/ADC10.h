/*This work is licensed under the Creative Commons Attribution-ShareAlike 3.0 United States License. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/3.0/us/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
*/

//Copyright 2011 Matthew Burmeister
//ADC

static unsigned int analogRead(unsigned int pin);
static void analogReference(unsigned int ref);


static unsigned int analogRead(unsigned int pin)
{
	//Ok, we need to setup the ADC10.
	//ADC10CTL0 |= SREF_0; //Set Ref to VCC and VDD
	ADC10CTL0 |= ADC10SHT_0; //Sample And Hold 4 clokcs
	//ADC10CTL0 |= ADC10SR; // enable for low power mode
	//ADC10CTL0 |= REFBURST;
	switch(pin)
	{
		case 0:
		ADC10CTL1 |= INCH_0;
		ADC10AE0 |= 0x01;
		break;
		
		case 1:
		ADC10CTL1 |= INCH_1;
		ADC10AE0 |= 0x02;
		break;
		
		case 2:
		ADC10CTL1 |= INCH_2;
		ADC10AE0 |= 0x04;
		break;
		
		case 3:
		ADC10CTL1 |= INCH_3;
		ADC10AE0 |= 0x08;
		break;
		
		case 4:
		ADC10CTL1 |= INCH_4;
		ADC10AE0 |= 0x10;
		break;
		
		case 5:
		ADC10CTL1 |= INCH_5;
		ADC10AE0 |= 0x20;
		break;
		
		case 6:
		ADC10CTL1 |= INCH_6;
		ADC10AE0 |= 0x40;
		break;
		
		case 7:
		ADC10CTL1 |= INCH_7;
		ADC10AE0 |= 0x80;
		break;
		
		case 0xFF:
		ADC10CTL1 |= INCH_10;
		break;
	}
	
	//ADC10CTL1 |= ISSH;
	ADC10CTL0 |= ADC10ON + ENC;
	ADC10CTL0 |= ADC10SC;
	
	while ((ADC10CTL1 & ADC10BUSY) != 1)
	{
	}
	
	return (ADC10MEM);
	
}


static void analogReference(unsigned int ref)
{
	switch (ref)
	{
		
		default:
			
		break;
		
		case DEFAULT:

			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_0;
		break;
	
	
		case INTERNAL:
	
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_0;
		break;
	
		case INTERNAL1V1:
	
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_1 + REFON;
			ADC10CTL0 &= ~REF2_5V;
		break;
	
		case INTERNAL2V56:
	
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_1 + REFON + REF2_5V;
		break;
	
		case EXTERNAL:
		
			ADC10CTL0 &= ~SREF_7; //Clear the register
			ADC10CTL0 |= SREF_2;
		break;
		
	}
}
