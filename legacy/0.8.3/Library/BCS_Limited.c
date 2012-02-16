static void setCPUFreq(unsigned int freq)

{
	switch (freq)
	{
		default:
		
		break;
		
		case M1:
		DCOCTL = 0;
		BCSCTL1 |= CALBC1_1MHZ;
		DCOCTL = CALDCO_1MHZ;
		setMCLK(DCOCLK, 1);
		_currentfreq = 1;
		break;
		
		case K500:
		DCOCTL = 0;
		BCSCTL1 |= CALBC1_1MHZ;
		DCOCTL = CALDCO_1MHZ;
		setMCLK(DCOCLK, 2);
		_currentfreq = 500;
		break;
		
		case K250:
		DCOCTL = 0;
		BCSCTL1 |= CALBC1_1MHZ;
		DCOCTL = CALDCO_1MHZ;
		setMCLK(DCOCLK, 4);
		_currentfreq = 250;
		break;
		
		case K125:
		DCOCTL = 0;
		BCSCTL1 |= CALBC1_1MHZ;
		DCOCTL = CALDCO_1MHZ;
		setMCLK(DCOCLK, 8);
		_currentfreq = 125;
		break;
		
		case K32:
		setMCLK(CRYSTAL, 1);
		_currentfreq = 32;
		break;
		
		case K22:
		setMCLK(VLOCLK, 1);
		_currentfreq = 22;
		break;
		
		case DAMNSLOW:
		setMCLK(VLOCLK, 8);
		_currentfreq = 2;
		break;
	}
}

static void setDCOFreq(unsigned int dco, unsigned int mod, unsigned int rsel)
{
	if (dco <= 7)
	{
		dco = dco << 5;
	}
	else
	{
		goto end;
	}
	
	DCOCTL = dco + mod;
	
	BCSCTL1 &= ~BIT3 + ~BIT2 + ~BIT1 + ~BIT0; //Clear rsel
	BCSCTL1 |= rsel; //Set 

	end:;
}

static inline void disableDCO(void)
{
	__bis_SR_register(SCG0);
}

static inline void enableDCO(void)
{
	__bic_SR_register(SCG0);
}

static void setMCLK(unsigned int source, unsigned int div)
{
	switch (source)
	{
		default:
		
		break;
		
		case DCOCLK:
		BCSCTL2 &= ~SELM_3;
		break;
		
		case VLOCLK:
		BCSCTL1 &= ~XTS; // low freq mode.
		BCSCTL3 |= LFXT1S_2; //Set 
		BCSCTL2 |= SELM_3; //Set to VLO Clock
		break;
		
		case CRYSTAL:
		BCSCTL1 &= ~XTS;
		BCSCTL3 &= ~LFXT1S_3; //Clear LFXTS.
		BCSCTL2 |= SELM_3;
		break;
	}
	
	switch (div)
	{
		default:
		
		break;
		
		case 1:
		BCSCTL2 &= ~DIVM_3;
		break;
		
		case 2:
		BCSCTL2 |= DIVM_1;
		break;
		
		case 4:
		BCSCTL2 |= DIVM_2;
		break;
		
		case 8:
		BCSCTL2 |= DIVM_3;
		break;
	}
}

static void setSMCLK(unsigned int source, unsigned int div)
{
	switch(source)
	{
		default:
		
		break;
		
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
	}
	
	switch(div)
	{
		default:
		
		break;
		
		case 1:
		BCSCTL2 &= ~DIVS_3; //clear divider setting
		BCSCTL2 |= DIVS_0;
		break;
		
		case 2:
		BCSCTL2 &= ~DIVS_3; //clear divider setting
		BCSCTL2 |= DIVS_1;
		break;
		
		case 4:
		BCSCTL2 &= ~DIVS_3; //clear divider setting
		BCSCTL2 |= DIVS_2;
		break;
		
		case 8:
		BCSCTL2 |= DIVS_3;
		break;
	}
}

static void setACLK(unsigned int source, unsigned int div)
{
	switch(source)
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
	
	switch(div)
	{
		default:
		
		break;
		
		case 1:
		BCSCTL1 &= ~DIVA_3;
		break;
		
		case 2:
		BCSCTL1 |= DIVA_1;
		break;
		
		case 4:
		BCSCTL1 |= DIVA_2;
		break;
		
		case 8:
		BCSCTL1 |= DIVA_3;
		break;
	}
}
