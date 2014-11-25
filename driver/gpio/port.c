void portWrite(enum port_names port, unsigned char data)
{
	switch (port)
	{
		case PORT1:
			P1OUT = data;
			break;
			
		case PORT2:
			P2OUT = data;
			break;
			
		case PORT3:
#		ifdef HAS_PORT3
			P3OUT = data;
#		endif
			break;
			
		case PORT4:
#		ifdef HAS_PORT4
			P4OUT = data;
#		endif
			break;
			
		default:
			break;
	}
	
	return;
}

unsigned char portRead(enum port_names port)
{
	switch (port)
	{
		case PORT1:
			return (P1IN);
		
		case PORT2:
			return (P2IN);
			
		case PORT3:
#		ifdef HAS_PORT3
			return (P3IN);
#		else
			return (0);
#		endif
		
		case PORT4:
#		ifdef	HAS_PORT4
			return (P4IN);
#		else
			return (0);
#		endif
			
		default:
			return (0);
	}
}
