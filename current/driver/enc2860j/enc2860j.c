/*
 * ENC2860J Hardware Link Layer
 *
 *
 *
 *
 *
 *
 *
 *
 */
 
#ifdef EASYMSPVER
	#if EASYMSPVER < 1.0
		# error "ENC2860J Link Layer Driver Requires EasyMSP Version 1.0 or higher."
	#endif
#else
	# error "EasyMSP is required for ENC2860J Link Layer Driver"
#endif
 
/* SPI Commands */
 
#define RCR 0x00
#define READ_CONTROL_REGISTER 0x00
 
#define RBM (BIT5)
#define READ_BUFFER_MEMORY (BIT5)
 
#define WCR (BIT6)
#define WRITE_CONTROL_REGISTER (BIT6)
 
#define WBM (BIT6 | BIT5)
#define WRITE_BUFFER_MEMORY (BIT6 | BIT5)
  
#define BFS (BIT7)
#define BIT_FIELD_SET (BIT7)
 
#define BFC (BIT7 | BIT5)
#define BIT_FIELD_CLEAR (BIT7 | BIT5)
 
#define SRC 0xFF
#define SYSTEM_RESET_COMMAND 0xFF
 
/*Global Registers */
 
#define EIE 0x1B
#define EIR 0x1C
#define ESTAT 0x1D
#define ECON2 0x1E
#define ECON1 0x1F
 
/*Bank 0 Registers */
 
#define ERDPTL 0x00
#define ERDPTH 0x01
#define EWRPTL 0x02
#define EWRPTH 0x03
#define ETXSTL 0x04
#define ETXSTH 0x05
#define ETXNDL 0x06
#define ETXNDH 0x07
#define ERXSTL 0x08
#define ERXSTH 0x09
#define ERXNDL 0x0A
#define ERXNDH 0x0B
#define ERXRDPTL 0x0C
#define ERXRDPTH 0x0D
#define ERXWRPTL 0x0E
#define ERXWRPTH 0x0F
#define EDMASTL 0x10
#define EDMASTH 0x11
#define EDMANDL 0x12
#define EDMANDH 0x13
#define EDMADSTL 0x14
#define EDMADSTH 0x15
#define EDMACSL 0x16
#define EDMACSH 0x17
 
/*Bank 1 Registers */
 
#define ETH0 0x00
#define ETH1 0x01
#define ETH2 0x02
#define ETH3 0x03
#define ETH4 0x04
#define ETH5 0x05
#define ETH6 0x06
#define ETH7 0x07
#define EPMM0 0x08
#define EPMM1 0x09
#define EPMM2 0x0A
#define EPMM3 0x0B
#define EPMM4 0x0C
#define EPMM5 0x0D
#define EPMM6 0x0E
#define EPMM7 0x0F
#define EPMCSL 0x10
#define EPMCSH 0x11
#define EPMOL 0x14
#define EPMOH 0x15
#define ERXRCON 0x18
#define EPKTCNT 0x19
 
/*Bank 2 Registers */

#define MACCON1 0x00
#define MACCON3 0x02
#define MACCON4 0x03
#define MABBIPG 0x04
#define MAIPGL 0x06
#define MAIPGH 0x07
#define MACLCON1 0x08
#define MACLCON2 0x09
#define MAMXFLL 0x0A
#define MAMXFLH 0x0B
#define MICMD 0x12
#define MIREGADR 0x14
#define MIWRL 0x16
#define MIWRH 0x17
#define MIRDL 0x18
#define MIRDH 0x19
 
 /*Bank 3 Registers */
 
#define MAADR5 0x00
#define MAADR6 0x01
#define MAADR3 0x02
#define MAADR4 0x03
#define MAADR1 0x04
#define MAADR2 0x05
#define EBSTSD 0x06
#define EBSTCON 0x07
#define EBSTCSL 0x08
#define EBSTCSH 0x09
#define MISTAT 0x0A
#define EREVID 0x12
#define ECOCON 0x15
#define EFLOCON 0x17
#define EPAUSL 0x18
#define EPAUSH 0x19


unsigned short int initController();

/* Low level functions */
void writeControl(unsigned char bank, unsigned char location, unsigned char data);
unsigned char readControl(unsigned char bank, unsigned char location);

void writeBuffer(unsigned short int location, unsigned char data);
unsigned char readBuffer(unsigned short int location);

void writePhy(unsigned char location, unsigned short int data);
unsigned short int readPhy(unsigned char location);

/* Link layer functions */
void spiConfig(unsigned short int DOUT, unsigned short int DIN, unsigned short int SCLK, unsigned short int CS, unsigned short int INT);
void spiOut(unsigned char data);
unsigned char spiIn(void);


void writeControl(unsigned char bank, unsigned char location, unsigned char data)
{
	spiOut(READ_CONTROL_REGISTER | ECON1); 
	auto unsigned char tempEcon1 = spiIn(void)l
	
	tempEcon1 &= ~BIT1 | ~BIT0;
	tempEcon1 |= bank;
	
	spiOut(WRITE_CONTROL_REGISTER | ECON1);
	spiOut(tempEcon1);
	
	spiOut(WRITE_CONTROL_REGISTER | location);
	spiOut(data);

	return;
}
