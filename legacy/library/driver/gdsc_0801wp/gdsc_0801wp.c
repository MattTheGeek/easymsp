/*
	Param:
	rs pin
	rw pin
	en pin
	pwr pin
*/
	
static unsigned short int rs;
static unsigned short int rw;
static unsigned short int en;
static unsigned short int pwr;
static unsigned short int ioStart;	
	
void lcdInit(const unsigned short int* param)
{
	rs = *param;
	param++;
	rw = *param;
	param++;
	en = *param;
	param++;
	pwr = *param;
	param++;
	ioStart = *param;
	
	pinMode(rs, OUTPUT);
	pinMode(rw, OUTPUT);
	pinMode(en, OUTPUT);
	pinMode(pwr, OUTPUT);
	pinMode(ioStart, OUTPUT);
	pinMode(ioStart + 1, OUTPUT);
	pinMode(ioStart + 2, OUTPUT);
	pinMode(ioStart + 3, OUTPUT);
	
	setHigh(pwr);
	
}