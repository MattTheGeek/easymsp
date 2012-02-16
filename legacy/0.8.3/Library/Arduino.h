//Arduino sub system

typedef unsigned char byte;
typedef unsigned char boolean;
typedef unsigned int word;

unsigned long systick = 0;

static void main()
{
	stopwd();
	setup();
	
	while(1)
	{
		loop()
	}
}

static void digitalWrite(unsigned int pin, unsigned int state)
{
	if(state == HIGH)
	{
		high(pin);
	}
	else
	{
		low(pin);
	}
}

static unsigned int digitalRead(unsigned int pin)
{
	return(read(pin));
}

static void pinMode(unsigned int pin, unsigned int mode)
{
	if (mode == INPUT)
	{
		input(pin);
	}
	else
	{
		output(pin);
	}
}

static void delayMicroseconds(unsigned int time)
{
	delayus(time);
}

static int micros(unsigned int time)
{
	return (systick);
}

static int millis(unsigned int time)
{
	return (systick / 1000);
}

static void interrupts(void)
{
	enableInterrupts();
}

static void noInterrupts(void)
{
	disableInterrupts();
}