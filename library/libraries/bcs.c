#if (_EM_SERIES == 2) || (_EM_SERIES == 'V') || (defined _EM_HASBCS)

extern unsigned short int setMCLK(unsigned short int source, unsigned short int divider)
{
	switch (source)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	switch (divider)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	return (SUCCESS);
}

extern unsigned short int setSMCLK(unsigned short int source, unsigned short int divider)
{
	switch (source)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	switch (divider)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	return (SUCCESS);
}

extern unsigned short int setACLK(unsigned short int source, unsigned short int divider)
{
	switch (source)
	{
		
		default:
			return (BAD_ARGUMENT);
	}
	
	switch (divider)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	return (SUCCESS);
}

extern unsigned short int setDCO(unsigned short int mode)
{
	switch (mode)
	{
		case OFF:
			_bic_SR_register(SCG0);
			break;
			
		case ON:
			_bis_SR_register(SCG0);
			break;
			
		case M1:
			
			if ( (CALBC1_1MHZ != 0xFFFF) && (CALDCO_1MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_1MHZ;
				DCOCTL = CALDCO_1MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;		

			
			
		case M8:
			
			if ( (CALBC1_8MHZ != 0xFFFF) && (CALDCO_8MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_8MHZ;
				DCOCTL = CALDCO_8MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;

		case M12:
			

			if ( (CALBC1_12MHZ != 0xFFFF) && (CALDCO_12MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_12MHZ;
				DCOCTL = CALDCO_12MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;

			
		case M16:
			

			if ( (CALBC1_16MHZ != 0xFFFF) && (CALDCO_16MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_16MHZ;
				DCOCTL = CALDCO_16MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;

		default:
			return (FAILURE);
	}
	
	return (SUCCESS);
}

#else

#endif
