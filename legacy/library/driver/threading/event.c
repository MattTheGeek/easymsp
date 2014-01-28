eventAttach
eventDetatch

static unsigned short int eventFlags = NULL;
static unsigned char eventMask = NULL;
static unsigned char eventSuspend = NULL;
static unsigned short int eventTable[8];

static void (*eventCall[8])(void);
/* void */
	
extern unsigned short int eventAttach(unsigned short int time, void (*handler)(void))
{
	auto unsigned short int count = NULL;
	auto unsigned short int handle;
	
	while ((eventMask & (1 << count)) > 0)
	{
		if (count > 7)
		{
			return(0);
		}
		else
		{
			count++;
		}
	}
	
	return (count);
}

extern unsigned short int eventSuspend(unsigned short int handle)
{
	if ((eventMask & (1 << handle)) > 0)
	{
		eventSuspend |= (1 << handle);
		return (SUCCESS);
	}
	else
	{
		return (FAILURE);
	}
}

extern unsigned short int eventResume(unsigned short int handle)
{
	if ((eventMask & (1 << handle)) > 0)
	{
		eventSuspend &= ~(1 << handle);
		return (SUCCESS);
	}
	else
	{
		return (FAILURE);
	}
}

static void	eventHandle(void)
{	
	register volatile unsigned short int count = 9;
	
	while (count != 0)
	{
		count--;
		
		if ((flags.Mask & (1 << count)) > 0)
		{
			if ((flags.Suspend & (1 << count)) > 0)
			{
				continue;
			}
			else
			{
				if (eventTable[count] == eventCounter)
				{
					(*eventCall[count])(); /* Call event handler */
				}
				
				continue;
			}
			
			continue;
		}
	}
	
	return;
}
