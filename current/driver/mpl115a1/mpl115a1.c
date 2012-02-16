#ifdef EASYMSPVER
	#if EASYMSPVER < 1.0
		# error "Driver MPL115A1 Requires EasyMSP Version 1.0 or higher."
	#endif
#else
	# error "EasyMSP is required for Driver MPL115A1"
#endif

static unsigned short int _DOUT = NULL;
static unsigned short int _DIN = NULL;
static unsigned short int _SCLK = NULL;
static unsigned short int _CS = NULL;

static signed short int A0 = NULL;
static signed short int B1 = NULL;
static signed short int B2 = NULL;
static signed short int C12 = NULL;
static signed short int C22 = NULL;


void main(void) 
{
	
}

void Write()
{
	
	
}

void LoadCo()
{
	/*
	[CS][0x88][0x00][0x8A][0x00][0x8C][0x00][0x8E][0x00][0x90][0x00][0x92][0x00]
	[0x94][0x00][0x96][0x00][0x98][0x00][0x9A][0x00][0x9C][0x00][0x9E][0x00][0x00]
	[CS]
	*/
	
	high(_CS);
	
	spiOut(_DOUT, _DIN, _SCLK, 0x88);
	auto unsigned char A0_high = spiIn(_DOUT, _DIN, _SCLK);
	
	A0 = A0_high << 8; //Shift Over
	
	spiOut(_DOUT, _DIN, _SCLK, 0x8A);
	auto unsigned char A0_low = spiIn(_DOUT, _DIN, _SCLK);
	
	A0 = A0 +
}

void spiOut(unsigned short int DOUT, unsigned short int DIN, unsigned short int SCLK, unsigned char data)
{
	
	auto unsigned short int bits = 8;
	
	do
	{
		if((data & 0x80) > 0) //Is bit set?
		{
			high(DOUT);
		}
		else
		{
			low(DOUT);
		}
		
		high(SCLK);
		
		data = data << 1;
		
		bits--;
		
		low(SCLK);
	}
	while(bits != 0);
	
	return;
}

unsigned char spiIn(unsigned short int DOUT, unsigned short int DIN, unsigned short int SCLK)
{
	
	auto unsigned short int bits = 8;
	auto unsigned char data = 0;
	
	do
	{
		high(SCLK);
		
		if(read(DIN) == true)
		{
			data |= 0x01;
		}
		
		low(SCLK);
		
		data = data << 1;
		bits--;
	}
	while(bits != 0);

	return(data);
}