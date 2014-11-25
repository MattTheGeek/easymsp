unsigned short int flashEraseSegment(unsigned short int password, enum flash_segments segment)
{

}

unsigned short int flashErase(unsigned short int password, unsigned short int segment)
{
	unsigned char * memptr = (segment * 512);

	if (password != FLASH_PASSWORD)
	{
		return (FAILURE);
	}
	else
	{
		/*
		 * The absolute maximum amount of flash segments that could be
		 * addressed with CPUX is 2048, and 128 on CPU.
		 */

		if (segment > 2048 && !(segment >= 0xFFF0))
		{
			return (FAILURE);
		}
	}

	WDTCTL = WDTPW + (((WDTCTL << 8) >> 8) | WDTHOLD);

	/* We assume that SMCLK is 1 Mhz. */
	FCTL2 = FWKEY + (FSSEL_3 | FN_3);
	FCTL3 = FWKEY;
	FCTL1 = FWKEY + (ERASE);

	/* Decode special segment options
	 *
	 * 0xFFFF - INFO D
	 * 0xFFFE - INFO C
	 * 0xFFFD - INFO B
	 * 0xFEEC - INFO A
	 * 0xFFFB - All flash segments.
	 * 0xFFFA - Program Memory
	 * 0xFFF9 - Reserved.
	 * ...
	 * 0xFFF0 - Reserved.
	 */
	switch (segment)
	{
		/* Must unlock info A before erasing info A! */
		case INFO_A:
		memptr = 0x1000 + (64 * 3) + 1;
		break;

		case INFO_B:
		memptr = 0x1000 + (64 * 2) + 1;
		break;

		case INFO_C:
		memptr = 0x1000 + (64 * 1) + 1;
		break;

		case INFO_D:
		memptr = 0x1000 + 1;
		break;

		case SEGMENT_ALL:
		FCTL1 = FWKEY + MERAS + ERASE;
		memptr = 0xFFFE;
		break;

		case SEGMENT_PROGRAM:
		FCTL1 = FWKEY + MERAS;
		memptr = 0xFFFE;
		break;

	}

	/* Lets do this! */
	*memptr = 0xFD;

	/* Clear the hold on the watchdog and let it run free. */
	WDTCTL = WDTPW + (((WDTCTL << 8) >> 8) & WDTHOLD);

	if ((FCTL3 & FAIL) > 0)
	{
		FCTL3 = FWKEY + EMEX;
		return (FAILURE);
	}

	FCTL3 = FWKEY + LOCK;

	return (SUCCESS);
}

unsigned short int flashNuke(unsigned short int password)
{

}

