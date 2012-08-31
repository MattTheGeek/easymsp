/* 

nmi_isrs 

*/
void (*NMIFunctionVector)(void) = NULL;

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V')



#pragma INTERRUPT(nmi_isr);
void interrupt nmi_isr(void);

#pragma vector=NMI_VECTOR;
void interrupt nmi_isr(void)
{
	if ((IFG1 & NMIIFG) > 0)
	{
		(*NMIFunctionVector)();
		
		IFG1 &= ~NMIIFG; //Clear flag
			
		return;
	}

	if ((IFG1 & OFIFG) > 0)
	{
		IFG1 &= ~OFIFG; //Clear flag
			
		if ((IFG1 & OFIFG) > 0)
		{
			register volatile unsigned short int count = 0;
		
			do
			{
				IFG1 &= ~OFIFG;
			}
			while (count != 100 && (IFG1 & OFIFG) > 0); /* Retry starting the crystal */
				
			if ((IFG1 & OFIFG) > 0) 
			{
				/* Log error */
				disableInterrupts();
				_low_power_mode_4();
			}
			
		}
			IE1 |= OFIE;
			return;
	}

	if ((FCTL3 & ACCVIFG) > 0)
	{
		/* Keep flag set for debugging
			IFG1 &= ~ACCVIFG; //Clear flag
		*/
		
		/* 
			Not quite sure how to go about handling a flash access violation.
			We could just ignore it and return execution to the user, However
			It might be wiser to shutdown and log it.
		*/
		
		/* Log error */	
		disableInterrupts();
		_low_power_mode_4();
	}

	/* If we get to here, who called this? */
	return;
}

#elif (_EM_SERIES == 5) || (_EM_SERIES == 6)

#pragma INTERRUPT(sys_nmi_isr);
void interrupt sys_nmi_isr(void);

#pragma vector=SYSNMI_VECTOR;
void interrupt sys_nmi_isr(void)
{
	switch (__even_in_range(SYSSNIV, SYSSNIV_VLRHIFG))
	{
		case SYSSNIV_NONE:

			break;
			
		case SYSSNIV_SVMLIFG:

			break;
			
		case SYSSNIV_SVMHIFG:

			break;

		case SYSSNIV_DLYLIFG:

			break;

		case SYSSNIV_DLYHIFG:

			break;

		case SYSSNIV_VMAIFG:
			SFRIFG1 &= ~VMAIFG; /* Clear VMA flag */
			break;

		case SYSSNIV_JMBINIFG:

			break;

		case SYSSNIV_JMBOUTIFG:

			break;

		case SYSSNIV_VLRLIFG:

			break;

		case SYSSNIV_VLRHIFG:

			break;

		default:
			_never_executed();
	}
	
	return;
}

#pragma INTERRUPT(user_nmi_isr);
void interrupt user_nmi_isr(void);

#pragma vector=UNMI_VECTOR;
void interrupt user_nmi_isr(void)
{
	switch (__even_in_range(SYSUNIV, SYSUNIV_BUSIFG))
	{

		case SYSUNIV_NONE:

			break;

		case SYSUNIV_NMIIFG:
				(*NMIFunctionVector)();
			break;

		case SYSUNIV_OFIFG:

			break;

		case SYSUNIV_ACCVIFG:
			disableInterrupts();
			_low_power_mode_4();
			break;

		case SYSUNIV_BUSIFG:

			break;

		default:
			_never_executed();
	}

	return;
}

#endif
