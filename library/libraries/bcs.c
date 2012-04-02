#if SERIES == 2

unsigned short int setCPUFreq(unsigned short int speed)
{
	switch (speed)
	{
		case M16:
			//
		break;


		case M12:
			//
		break;


		case M8:
			//
		break;


		case M6:
			//
		break;


		case M4:
			//
		break;


		case M2:
			//
		break;


		case M1:
			//
		break;


		case K500:
			//
		break;


		case K125:
			//
		break;


		case K32:
			//
		break;


		case K22:
			//
		break;


		case DAMNSLOW:
			//
		break;


		default:

		return(1);
	}

	return(0);
}

unsigned short int setDCOFreq(unsigned short int _DCO, unsigned short int _MOD, unsigned short int _RSEL)
{
	return(0);
}

unsigned short int setMCLK(unsigned short int source, unsigned short int divider)
{
	switch (source)
	{
		case DCOCLK:
			BCSCTL2 &= ~SELM_3;
		break;

		case LFXT1SCLK:
			BCSCTL2 |= SELM_3;
		break;

		default:
			return(1);
	}

	BCSCTL2 &= ~DIVM_3; //Clear divider bits

	switch (divider)
	{
		case 1:
			/* BCSCTL2 &= ~DIVM_3;
			 * Clearing MCLK clock divider bits is no longer required as it is cleared before the switch.
			 */
			break;

		case 2:
			/* BCSCTL2 &= ~DIVM_3;
			 * Clearing MCLK clock divider bits is no longer required as it is cleared before the switch.
			 */
			BCSCTL2 |= DIVM_1;
			break;

		case 4:
			/* BCSCTL2 &= ~DIVM_3;
			 * Clearing MCLK clock divider bits is no longer required as it is cleared before the switch.
			 */
			BCSCTL2 |= DIVM_2;
			break;

		case 8:
			BCSCTL2 |= DIVM_3;
			break;

		default:
			return(2);
	}

	return(0);
}

unsigned short int setSMCLK(unsigned short int source, unsigned short int divider)
{
	if (source == DCOCLK)
	{
		BCSCTL2 &= ~SELS;
	}
	else if (source == LFXT1SCLK)
	{
		BCSCTL2 |= SELS;
	}
	else
	{
		return(1);
	}

	BCSCTL2 &= ~DIVS_3;

	switch (divider)
	{
		case 1:
			//Do nothing, as the bits are already clear.
			break;

		case 2:
			BCSCTL2 |= DIVS_1;
			break;

		case 4:
			BCSCTL2 |= DIVS_2;
			break;

		case 8:
			BCSCTL2 |= DIVS_3;
			break;

		default:
			return(2);
	}

	return(0);
}

unsigned short int setACLK(unsigned short int source, unsigned short int divider)
{

	BCSCTL3 &= ~LFXT1S_3;

	switch (source)
	{
		case CRYSTAL:
			/* BCSCTL3 &= ~LFXT1S_3;
			 * Clearing source is not required, as it is cleared before the switch.
			 */
			break;

		case VLO:
			/* BCSCTL3 &= ~LFXT1S_3;
			 * Clearing source is not required, as it is cleared before the switch.
			 */
			BCSCTL3 |= LFXT1S_2;
			break;

		case DIGITAL:
			BCSCTL3 |= LFXT1S_3;
			break;

		default:
			return(1);
	}


	BCSCTL1 &= ~DIVA_3; //Clear divider bits

	switch (divider)
	{
		case 1:
			BCSCTL1 &= ~DIVA_3;
			break;

		case 2:
			/*
			* No longer needed as the ACLK clock divder setting is cleared before the switch.
			* BCSCTL1 &= ~DIVA_3; //Clear divider bits
			*/
			BCSCTL1 |= DIVA_1;
			break;

		case 4:
			/*
			 * No longer needed as the ACLK clock divder setting is cleared before the switch.
			 * BCSCTL1 &= ~DIVA_3; //Clear divider bits
			 */
			BCSCTL1 |= DIVA_2;
			break;

		case 8:
			BCSCTL1 |= DIVA_3;
			break;

		default:
			return(2);
	}

	return(0);
}

void disableDCO(void)
{

}

void enableDCO(void)
{

}

unsigned short int getCPUFreq(void)
{
	return(currentcpuspeed);
}

#endif
