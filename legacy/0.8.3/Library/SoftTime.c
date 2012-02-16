static inline void delayus(register unsigned int time)
{
     while(time != 0)
     {
              _us();
              time--;
     }
}  

//_us
//Used for internal use only
static inline void _us(void)
{
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
	asm("	nop	");
}

//delayms
//--------------------------------------------------------
//Delay execution by "x" miliseconds

static inline void delayms(register unsigned int time)
{
	
	while (time != 0)
	{
          register unsigned int us = 21;
          
          while(us != 0)
          {
                   delayus(1);
                   us--;
          }
          
          time--;
     }
}


//delaysec
//--------------------------------------------------------
//Delay execution by "x" seconds.

static inline void delaysec(register unsigned int time)
{
	while(time != 0)
	{
		delayms(1000);
		time--;
	}
}

static inline void delay(register unsigned int time)
{
	delayms(time);
}
