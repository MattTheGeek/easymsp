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

#if SERIES == 2

#ifndef NOSETUP

#ifndef NOINIT
extern void init(void);
#endif

#ifndef NOLOOP
extern void loop(void);
#endif

static volatile bool EasyMSP_Execute = true; //This varible tells the while loop when to stop executing the loaded EasyMSP program.
static volatile bool EasyMSP_HasFlashSettings = false;

#pragma FUNC_NEVER_RETURNS ( main );
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //Stop the watchdog from resetting the system.

    //Lets do clock setup
#ifdef CRYSTAL
    BCSCTL3 &= ~LFXT1S_3; //Use a external 32Khz crystal.

#ifdef CAP12

    BCSCTL3 |= XCAP_3;
#endif

#ifdef CAP10

    BCSCTL3 |= XCAP_2;
#endif

#ifdef CAP6

    BCSCTL3 |= XCAP_1;
#endif

#ifdef CAP1

    BCSCTL3 &= ~XCAP_3;
#endif

#else

    BCSCTL3 |= LFXT1S_2; //Use VLO for ACLK

#ifdef DIGITAL

    BCSCTL3 |= LFXT1S_3; //Use a external digital clock source for ACLK;
#endif

#endif

#if ACLKDIV == 2

    BCSCTL1 |= DIVA_1;
#endif

#if ACLKDIV == 4

    BCSCTL1 |= DIVA_2;
#endif

#if ACLKDIV == 8

    BCSCTL1 |= DIVA_3;
#endif

#if MCLKSOURCE == ACLK

    BCSCTL2 |= SELM_3;
#endif

#if MCLKDIV == 2

    BCSCTL2 |= DIVM_1;
#endif

#if MCLKDIV == 4

    BCSCTL2 |= DIVM_2;
#endif

#if MCLKDIV == 8

    BCSCTL2 |= DIVM_3;
#endif

#if SMCLKSOURCE == ACLK

    BCSCTL2 |= SELS;
#endif

#if SMCLKDIV == 2

    BCSCTL2 |= DIVS_1;
#endif

#if SMCLKDIV == 4

    BCSCTL2 |= DIVS_2;
#endif

#if SMCLKDIV == 8

    BCSCTL2 |= DIVS_3;
#endif


#ifndef NO_IO_SETUP
    //Setup IO
    P1OUT = 0;
    P1DIR = 0xFF; //All outputs, low.

    P2OUT = 0;
    P2DIR = 0xFF; //All outputs, low

#ifdef HASPORT3

    P3OUT = 0;
    P3DIR = 0xFF; //All outputs, low.

#endif

#endif

    //Lets Check if we have settings in flash, and if so, override the compiled settings.
    ///Todo: Write Flash Settings Loader.

    asm("	EINT	"); //Enable interrupts

#ifndef NOINIT //If the user has declared NOINIT, then do not include and execute init()

    init(); //Call program init()

#endif

#ifndef NOLOOP //If the user has declared NOLOOP, then do not include and execute loop

    do //Keep executing loop until a system reset or until EasyMSP_Execute is 0
    {
        loop(); //Call program loop
    }
    while(EasyMSP_Execute != false);

#endif

    shutdown(); //Enter into the lowest power mode. The EasyMSP program has finished executing.
}

#endif

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

#endif

#if SERIES == 5

#ifndef NOINIT
extern void init(void);
#endif

#ifndef NOLOOP
extern void loop(void);
#endif

static volatile unsigned short int EasyMSPExecute = 1;

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;

	#ifndef NOINIT
		init();
	#endif

	#ifndef NOLOOP

		while(EasyMSPExecute)
		{
			loop();
		}

	#endif
}

#endif
