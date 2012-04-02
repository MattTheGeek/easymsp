


inline void setCPUVoltage(unsigned short int level)
{
	switch (level)
	{
		case 0:
			PMMCTL0 = PMMPW + (PMMCTL0_L & PMMCOREV_0);
		break;
		
		case 1:
			PMMCTL0 = PMMPW + (PMMCTL0_L | PMMCOREV_1);
		break;
		
		case 2:
			PMMCTL0 = PMMPW + (PMMCTL0_L | PMMCOREV_2);
		break;
	
		case 3:
			PMMCTL0 = PMMPW + (PMMCTL0_L | PMMCOREV_3);
		break;
		
		default:
		
		break;
	}
}
		
inline void issuePOR(void)
{
	PMMCTL0 = PMMPW + PMMSWPOR;
}

inline void issueBOR(void)
{
	PMMCTL0 = PMMPW + PMMSWBOR;
}
