inline void setMCLK(unsigned short int source, unsigned short int div)
{
	switch (source)
	{
		case DCOCLK:
			BCSCTL2 &= ~SELM_3;
			break;
			
		case VLOCLK:
			BCSCTL1 &= ~XTS; // low freq mode.
			BCSCTL3 |= LFXT1S_2; //Set LFXT1S to source the VLO
			BCSCTL2 |= SELM_3; //Set to VLO Clock
			break;
			
		case CRYSTAL:
			BCSCTL1 &= ~XTS;
			BCSCTL3 &= ~LFXT1S_3; //Clear LFXTS.
			BCSCTL2 |= SELM_3;
			break;
			
		default:
			_never_executed();
	}
	
	switch (div)
	{
		case by_1:
			BCSCTL2 &= ~DIVM_3;
			break;
			
		case by_2:
			BCSCTL2 &= ~DIVM_3;
			BCSCTL2 |= DIVM_1;
			break;
			
		case by_4:
			BCSCTL2 &= ~DIVM_3;
			BCSCTL2 |= DIVM_2;
			break;
			
		case by_8:
			BCSCTL2 &= ~DIVM_3;
			BCSCTL2 |= DIVM_3;
			break;
			
		default:
			_never_executed();
	}
}

inline void setSMCLK(unsigned short int source, unsigned short int div)
{
	switch (source)
	{
		case VLOCLK:
			BCSCTL3 |= LFXT1S_2;
			BCSCTL2 |= SELS;
			break;
			
		case DCOCLK:
			BCSCTL2 &= ~SELS;
			break;
			
		case CRYSTAL:
			BCSCTL1 &= ~XTS;
			BCSCTL3 |= LFXT1S_0 | XCAP_3;
			BCSCTL2 |= SELS;
			break;
			
		default:
			_never_executed();
	}
	
	switch (div)
	{
		case by_1:
			BCSCTL2 &= ~DIVS_3; //clear divider setting
			BCSCTL2 |= DIVS_0;
			break;
			
		case by_2:
			BCSCTL2 &= ~DIVS_3; //clear divider setting
			BCSCTL2 |= DIVS_1;
			break;
			
		case by_4:
			BCSCTL2 &= ~DIVS_3; //clear divider setting
			BCSCTL2 |= DIVS_2;
			break;
			
		case by_8:
			BCSCTL2 |= DIVS_3;
			break;
			
		default:
			_never_executed();
	}
}

inline void setACLK(unsigned short int source, unsigned short int div)
{
	switch (source)
	{
		default:
			
			break;
			
		case CRYSTAL:
			BCSCTL1 &= ~XTS;
			BCSCTL3 |= LFXT1S_0 | XCAP_3;
			break;
			
		case VLOCLK:
			BCSCTL3 |= LFXT1S_2;
			break;
			
	}
	
	BCSCTL1 &= ~DIVA_3;
	
	switch (div)
	{
		case by_2:
			BCSCTL1 |= DIVA_1;
			break;
			
		case by_4:
			BCSCTL1 |= DIVA_2;
			break;
			
		case by_8:
			BCSCTL1 |= DIVA_3;
			break;
			
		default:
		case by_1:
			_never_executed();

	}
	
	return;
}
