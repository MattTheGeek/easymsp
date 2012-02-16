/*
 *	EasyLink RF Driver for CC2500 Series Radios
 */ 

#ifdef EASYMSPVER
	#if EASYMSPVER < 1.0
		# error "EasyLink RF For CC2500 Radios Requires EasyMSP Version 1.0 or higher."
	#endif
#else
	# error "EasyMSP is required for EasyLink RF For CC2500 Radios."
#endif


unsigned short int radioStart(unsigned short int* InitTable);

/* InitTable
 *
 *	The InitTable Array provides the required information to start the CC2500 radio.
 *
 * [MagicNumber]
 * [BaudRate]
 * [Channel]
 * [PowerMode]
 * [CommMode]
 * [SDI]
 * [SDO]
 * [SCLK]
 * [CS]
 * [INT]
 *
 * Selectable Baud rates are 500K, 250K, 16.9K, 9600.
 *
 * If CommMode USCIA or USCIB is selected, You may omit SDI, SDO, SCLK, and CS. INT should never be omited for any mode.
 * If you are using the USI, You may omit SDI, SDO, and SCLK only. You can not omit any pins if you are using BitBang mode.
 *
 * The max size of the InitTable is 20 bytes or 10 words long.
*/

void radioStop(void);

unsigned short int checkForPacket(void);

unsigned short int* getPacket(void);
unsigned short int sendPacket(unsigned short int address,
											unsigned short int port,
											unsigned short int *data);
											
unsigned short int sendBroadcast(unsigned short int* data);
unsigned short int sendPing(unsigned short int address);
unsigned short int* resolveDeviceInfo(unsigned short int address);