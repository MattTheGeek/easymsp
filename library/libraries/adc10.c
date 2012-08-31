inline void analogOff(void)
{
	
}

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')

unsigned short int analogRead(unsigned short int pin)
{
	
	if (pin > 7) 
	{
		return (NULL); /* Return if pin number is out of range. */
	}

	ADC10CTL1 &= ~INCH_15; /* We can't clear the whole ADC10CTL1 register, so just NAND bits 11 to 8 */
	ADC10CTL1 |= (pin << 12);	/*  Set the analog channel to pin. By shifting pin by 12 bits*/
	ADC10AE0 = (1 << pin); /* Set the analog channel enable */
	
	return (ADC10MEM);

}

#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)
/* The F5/F6 family MSP430s have a different ADC10 features */

unsigned short int analogRead(unsigned short int pin)
{
	/* todo: Rewrite ADC10 code */
	ADC10MCTL0 &= ~ADC10INCH_15;
	ADC10MCTL0 |= (pin);

	return (ADC10MEM);
}

#endif

#pragma vector = ADC10_VECTOR;
interrupt void adc10_isr(void)
{
	return;
}
