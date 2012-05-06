#if SERIES == 2

unsigned short int analogRead(unsigned short int pin)
{
	/* todo: Rewrite ADC10 code */
	ADC10CTL1 &= ~INCH_15;
	ADC10CTL1 |= (pin << 12);
	ADC10AE0 = (1 << pin);

	return (NULL);

}

#elif SERIES == 5

unsigned short int analogRead(unsigned short int pin)
{
	/* todo: Rewrite ADC10 code */
	ADC10MCTL0 &= ~ADC10INCH_15;
	ADC10MCTL0 |= (pin);

	return (NULL);
}

#endif

#pragma vector = ADC10_VECTOR;
interrupt void adc10_isr(void)
{
	powerModeOff();
}
