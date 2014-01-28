#define OLIMEXINO5510
#include "EasyMSP.h"

void init(void)
{
	pinMode(LED, OUTPUT);
}

void loop(void)
{
	setHigh(LED);
	delayMs(500);
	setLow(LED);
	delayMs(500);
}