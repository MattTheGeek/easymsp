void setPowerMode(unsigned short int state)
{
	switch (state)
	{
		case 0:
			_low_power_mode_0();
			break;
			
		case 1:
			_low_power_mode_1();
			break;
			
		case 2:
			_low_power_mode_2();
			break;
			
		case 3:
			_low_power_mode_3();
			break;
			
		case 4:
			_low_power_mode_4();
			break;
			
		case 0x0F:
			_low_power_mode_off_on_exit;
			break;
			
		default:
	}
	
	return;
}

unsigned short int getPowerMode()
{
	unsigned short int srtemp = _get_SR_register_on_exit();
	
	srtemp &= (CPUOFF | OSCOFF | SCG1 | SCG0);
	
	switch (srtemp)
	{
		case 0:
			return (ACTIVE);
			
		case CPUOFF:
			return (MODE0);
			
		case (CPUOFF + OSCOFF):
}

void shutdown()
{

}

void reboot()
{
	
}