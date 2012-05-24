inline void analogOff(void)
{
	
}

#if SERIES == 2

unsigned short int analogRead(unsigned short int pin)
{
	/* todo: Rewrite ADC10 code */
	
	if (pin > 7) 
	{
		/* Return if pin number is out of range. */
		return (NULL);
	}

	ADC10CTL1 &= ~INCH_15; /* Clear the current analog channel selection */
	ADC10CTL1 |= (pin << 12);	/*  Set the analog channel to pin. By shifting pin by 12 bits*/
	ADC10AE0 = (1 << pin); /* Set the analog channel enable */
	
	return (ADC10MEM);

}

#elif SERIES == 5

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
	powerModeOff();
}
