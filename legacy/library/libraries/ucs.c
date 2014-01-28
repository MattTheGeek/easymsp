







inline void setMCLK(const unsigned short int source, const unsigned short int divider)
{
	switch (source)
	{
		case XT2CLK:
			UCSCTL4 &= ~SELM_7;
			UCSCTL4 |= SELM_5;
			break;
			
		case DCOCLKDIV:
			UCSCTL4 &= ~SELM_7;
			UCSCTL4 |= SELM_4;
			break;
			
		case DCOCLK:
			UCSCTL4 &= ~SELM_7;
			UCSCTL4 |= SELM_3;
			break;
			
		case REFOCLK:
			UCSCTL4 &= ~SELM_7;
			UCSCTL4 |= SELM_2;
			break;
			
		case VLOCLK:
			UCSCTL4 &= ~SELM_7;
			UCSCTL4 |= SELM_1;
			break;
			
		case XT1CLK:
			UCSCTL4 &= ~SELM_7;
			break;
			
		default:
			break;
	}
	
	switch (divider)
	{
		case by_32:
			UCSCTL5 &= ~DIVM_7;
			UCSCTL5 |= DIVM_5;
			break;
			
		case by_16:
			UCSCTL5 &= ~DIVM_7;
			UCSCTL5 |= DIVM_4;
			break;
			
		case by_8:
			UCSCTL5 &= ~DIVM_7;
			UCSCTL5 |= DIVM_3;
			break;
			
		case by_4:
			UCSCTL5 &= ~DIVM_7;
			UCSCTL5 |= DIVM_2;
			break;
			
		case by_2:
			UCSCTL5 &= ~DIVM_7;
			UCSCTL5 |= DIVM_1;
			break;
			
		case by_1:
			UCSCTL5 &= ~DIVM_7;
			break;
			
		default:
			break;
	}
}

inline void setSMCLK(const unsigned short int source, const unsigned short int divider)
{
	switch (source)
	{
		case XT2CLK:
			UCSCTL4 &= ~SELS_7;
			UCSCTL4 |= SELS_5;
			break;
			
		case DCOCLKDIV:
			UCSCTL4 &= ~SELS_7;
			UCSCTL4 |= SELS_4;
			break;
			
		case DCOCLK:
			UCSCTL4 &= ~SELS_7;
			UCSCTL4 |= SELS_3;
			break;
			
		case REFOCLK:
			UCSCTL4 &= ~SELS_7;
			UCSCTL4 |= SELS_2;
			break;
			
		case VLOCLK:
			UCSCTL4 &= ~SELS_7;
			UCSCTL4 |= SELS_1;
			break;
			
		case XT1CLK:
			UCSCTL4 &= ~SELS_7;
			break;
			
		default:
			break;
	}
	
	switch (divider)
	{
		case by_32:
			UCSCTL5 &= ~DIVS_7;
			UCSCTL5 |= DIVS_5;
			break;
			
		case by_16:
			UCSCTL5 &= ~DIVS_7;
			UCSCTL5 |= DIVS_4;
			break;
			
		case by_8:
			UCSCTL5 &= ~DIVS_7;
			UCSCTL5 |= DIVS_3;
			break;
			
		case by_4:
			UCSCTL5 &= ~DIVS_7;
			UCSCTL5 |= DIVS_2;
			break;
			
		case by_2:
			UCSCTL5 &= ~DIVS_7;
			UCSCTL5 |= DIVS_1;
			break;
			
		case by_1:
			UCSCTL5 &= ~DIVS_7;
			break;
			
		default:
			break;
	}
}

inline void setACLK(const unsigned short int source, const unsigned short int divider)
{
	switch (source)
	{
		case XT2CLK:
			UCSCTL4 &= ~SELA_7;
			UCSCTL4 |= SELA_5;
			break;
			
		case DCOCLKDIV:
			UCSCTL4 &= ~SELA_7;
			UCSCTL4 |= SELA_4;
			break;
			
		case DCOCLK:
			UCSCTL4 &= ~SELA_7;
			UCSCTL4 |= SELA_3;
			break;
			
		case REFOCLK:
			UCSCTL4 &= ~SELA_7;
			UCSCTL4 |= SELA_2;
			break;
			
		case VLOCLK:
			UCSCTL4 &= ~SELA_7;
			UCSCTL4 |= SELA_1;
			break;
			
		case XT1CLK:
			UCSCTL4 &= ~SELA_7;
			break;
			
		default:
			break;
	}
	
	switch (divider)
	{
		case by_32:
			UCSCTL5 &= ~DIVA_7;
			UCSCTL5 |= DIVA_5;
			break;
			
		case by_16:
			UCSCTL5 &= ~DIVA_7;
			UCSCTL5 |= DIVA_4;
			break;
			
		case by_8:
			UCSCTL5 &= ~DIVA_7;
			UCSCTL5 |= DIVA_3;
			break;
			
		case by_4:
			UCSCTL5 &= ~DIVA_7;
			UCSCTL5 |= DIVA_2;
			break;
			
		case by_2:
			UCSCTL5 &= ~DIVA_7;
			UCSCTL5 |= DIVA_1;
			break;
			
		case by_1:
			UCSCTL5 &= ~DIVA_7;
			break;
			
		default:
			break;
	}
}
