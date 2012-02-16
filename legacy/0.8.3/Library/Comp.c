
static void compareConfig(unsigned int ref, unsigned int _short, unsigned int filter, unsigned int exchange, unsigned int refsel)
{
	if (exchange == YES)
	{
		CACTL1 |= CAEX;
	}
	else
	{
		CACTL1 &= ~CAEX;
	}
	
	if (refsel == POSITIVE)
	{
		if (exchange == YES)
		{
			CACTL1 |= BIT6;
		}
		else
		{
			CACTL1 &= ~BIT6;
		}
	}
	else
	{
		if (exchange == YES)
		{
			CACTL1 &= ~BIT6;
		}
		else
		{
			CACTL1 |= BIT6;
		}
	}
	
	switch (ref)
	{
		default:
		
		break;
		
		case EXTERNAL:
			CACTL1 &= ~BIT5 + ~BIT4;
		break;
		
		case VDDQUARTER:
			CACTL1 |= BIT4;
			CACTL1 &= ~BIT5;
		break;
		
		case VDDHALF:
			CACTL1 |= BIT5;
			CACTL1 &= ~BIT4;
		break;
		
		case DIODE:
			CACTL1 |= BIT5 + BIT4;
		break;
	}
	
	
	if (_short == YES)
	{
		CACTL2 |= CASHORT;
	}
	else
	{
		CACTL2 &= ~CASHORT;
	}
	
	
	if (filter == YES)
	{
		CACTL2 |= CAF;
	}
	else
	{
		CACTL2 &= ~CAF;
	}
}

static unsigned int compare(unsigned int pospin, unsigned int negpin)
{
	CACTL2 |= (pospin << 3);
	
	switch (negpin)
	{
		case 0:
			CACTL2 &= ~P2CA0 + ~P2CA4;
		break;
		
		case 1:
			CACTL2 |= P2CA0;
			CACTL2 &= ~P2CA4;
		break;
		
		case 2:
			CACTL2 |= P2CA4;
			CACTL2 &= ~P2CA0;
		break;
		
		case 3:
			CACTL2 |= P2CA4 + P2CA0;
		break;
	}
	
	CACTL1 |= CAON;
	
	unsigned int result=0;
	
	result = CACTL2 & CAOUT;
	
	if (result > 0)
	{
		CACTL1 &= ~CAON;
		return (1);
	}
	else
	{
		CACTL1 &= ~CAON;
		return (0);
	}
}
