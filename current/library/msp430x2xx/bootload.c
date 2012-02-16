/*
 * bootload.c
 * EasyMSP Serial Bootloader
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
 
#define BITBANG 1
#define USCI 2
#define TIMER 3 
 
#define RXPIN 2
#define TXPIN 1
#define BAUD 9600
#define MODE BITBANG
#define TIMEOUT
 
int main(void)
{
	//First step in the bootloading phase is to stop the watchdog.
	WDTCTL = WDTPW + WDTHOLD;
	
}