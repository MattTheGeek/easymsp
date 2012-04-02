/* info: This is currently just a shell for the USB bootloader. */

#define NO_REQUEST 0x00
#define DEVICE 0x01
#define BOARD 0x02
#define BOOT_VER 0x03

#define UNLOCK_KEY "EaSymsP"

#define INFO 0x01
#define UNLOCK 0x02
#define READ 0x03
#define WRITE 0x04
#define ERASE 0x05
#define SPECIAL 0x06

#define FLASH 0x01
#define RAM 0x02
#define REGISTER 0x03
#define SEGMENT 0x01
#define MAIN 0x02
#define MASS_ERASE 0x03
#define SET_PC 0x01
#define CALL 0x02
#define REBOOT 0x03

#include <msp430f5510.h>

void command(void);
void init(void);

volatile unsigned short int unLocked = 0;
volatile unsigned char commandString[7] = {0};

void main(void)
{
	init();
}



void init(void)
{
	WDTCTL = WDTPW + WDTHOLD;
}

void command(void)
{
	switch(commandString[0])
	{
		case INFO:

			break;

		case UNLOCK:
			
			break;

		case READ:

			if (unLocked > 0)
			{

			}
			else
			{

			}

		break;

		case WRITE:

			if (unLocked > 0)
			{

			}
			else
			{


			}

		break;

		case ERASE:

			if (unLocked > 0)
			{

			}
			else
			{

			}

		break;

		case SPECIAL:

			if (unLocked > 0)
			{

			}
			else
			{

			}

		break;

		default:
			_never_executed();

	}
}
