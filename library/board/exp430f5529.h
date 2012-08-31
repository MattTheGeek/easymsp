

inline void boardinit(void)
{
	 // Setup XT1 and XT2
    XT1_XT2_PORT_SEL |= XT1_ENABLE + XT2_ENABLE;

    // Configure LED ports
    LED145678_PORT_OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5);
    LED145678_PORT_DIR |= BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5;
    LED23_PORT_OUT &= ~(BIT1 + BIT2);
    LED23_PORT_DIR |= BIT1 + BIT2;

    // Configure button ports
    PADIR &= ~0x0480;               // Buttons on P1.7/P2.2 are inputs

    // Configure CapTouch ports
    P1OUT &= ~0x7E;
    P1DIR |= 0x7E;
    P6OUT = 0x00;
    P6DIR = 0x00;

    // Configure Cma3000 ports
    P2DIR &= ~BIT5;                 // ACCEL_INT pin is input
    P2OUT &= ~BIT7;                 // SCK
    P2DIR |= BIT7;
    P3OUT &= ~(BIT3 + BIT5 + BIT6); // ACCEL_SIMO, ACCEL_CS, ACCEL_PWR to low
    P3DIR &= ~BIT4;                 // ACCEL_SOMI pin is input
    P3DIR |= BIT3 + BIT5 + BIT6;    // ACCEL_SIMO, ACCEL_CS, ACCEL_PWR as outp

    // Configure Dogs102x6 ports
    P5OUT &= ~(BIT6 + BIT7);        // LCD_C/D, LCD_RST
    P5DIR |= BIT6 + BIT7;
    P7OUT &= ~(BIT4 + BIT6);        // LCD_CS, LCD_BL_EN
    P7DIR |= BIT4 + BIT6;
    P4OUT &= ~(BIT1 + BIT3);        // SIMO, SCK
    P4DIR &= ~BIT2;                 // SOMI pin is input
    P4DIR |= BIT1 + BIT3;

    // Configure SDCard ports
    P3OUT |= BIT7;                  // SD_CS to high
    P3DIR |= BIT7;

    // Configure Wheel ports
    P6DIR &= ~BIT5;                 // A5 ADC input
    P8OUT &= ~BIT0;                 // POT_PWR
    P8DIR |= BIT0;

    // Configure unused ports for low power
    P2OUT &= ~(BIT0 + BIT1 + BIT3 + BIT4 + BIT6);
    P2DIR |= BIT0 + BIT1 + BIT3 + BIT4 + BIT6;

    P3OUT &= ~(BIT0 + BIT1 + BIT2);
    P3DIR |= BIT0 + BIT1 + BIT2;

    P4OUT &= ~(BIT0 + BIT6 + BIT7);
    P4DIR |= BIT0 + BIT6 + BIT7;

    P5OUT &= ~BIT1;
    P5DIR |= BIT1;

    P6OUT &= ~(BIT6 + BIT7);
    P6DIR |= BIT6 + BIT7;

    P7OUT &= ~(BIT0 + BIT1 + BIT2 + BIT3 + BIT5 + BIT7);
    P7DIR |= BIT0 + BIT1 + BIT2 + BIT3 + BIT5 + BIT7;
}