static unsigned short int _timeoutValue = 0;

void timeoutSet(unsigned short int time)
{
	_timeoutValue = time;
	return;
}

unsigned short int timeout(void)
{
	if (_timeoutValue != 0)
	{
		timeoutValue--;
		return (0);
	}
	else
	{
		return (1);
	}
}