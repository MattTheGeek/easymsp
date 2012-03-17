/*
 * EasyMSP.c
 * One of the core libraries to EasyMSP. This is what executes EasyMSP programs.
 *
 * Written by:
 * Matthew Burmeister
 * Copyright 2011 All Rights Reserved.
 *
 *
 *
 */


#ifndef NOSETUP

#ifndef NOINIT
extern void init(void);
#endif

#ifndef NOLOOP
extern void loop(void);
#endif


static volatile bool EasyMSP_Execute = true;

#pragma FUNC_NEVER_RETURNS ( main );
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //Stop the watchdog from resetting the system.

	#if SERIES == 2
    	/* Series 2 setup code */
	#elif SERIES == 5
    	/* Series 5 setup code */
	#else
		#error "No Series defined. Can't Compile"
	#endif

	#ifndef NOINIT //If the user has declared NOINIT, then do not include and execute init()

		init(); //Call program init()

	#endif

	#ifndef NOLOOP //If the user has declared NOLOOP, then do not include and execute loop

		do //Keep executing loop until a system reset or until EasyMSP_Execute is 0
		{
			loop(); //Call program loop
		}
		while(EasyMSP_Execute);

	#endif

    shutdown();
}


#if SERIES == 2

#ifndef CUSTOM_NMI

#pragma vector=NMI_VECTOR
static __interrupt void nonmask_isr(void)
{
    if ((IFG1 & NMIIFG) > 0)
    {
        IFG1 &= ~NMIIFG; //Clear flag

        /* Handle the NMI */
        return;
    }

    if ((IFG1 & OFIFG) > 0)
    {
        IFG1 &= ~OFIFG; //Clear flag

        /* handle oscilator fault */
        return;
    }

    if ((IFG1 & ACCVIFG) > 0)
    {
        IFG1 &= ~ACCVIFG; //Clear flag

        /* Handle flash access violation. */
        return;
    }

    /* If we get to here, who the hell called this? */
    return;
}

#endif

#if SERIES == 5

#endif

#endif

#endif
