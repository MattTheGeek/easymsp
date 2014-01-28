//Button.c

bool readButton(unsigned short int pin)
{
	auto bool result = read(pin);
	
	_delay_cycles(5000);
	
	auto bool result2 = read(pin);
	
	if (result == true && result2 == true)
	{
		if (buttonState == true)
		{
			return (false);
		}
		else
		{
			return (true);
		}
	}
	else
	{
		if (buttonState = true)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
}

void buttonSetup(unsigned short int idleState)
{
	if (idleState == HIGH)
	{
		buttonState = true;
	}
	else
	{
		buttonState = false;
	}
	
	return;
}