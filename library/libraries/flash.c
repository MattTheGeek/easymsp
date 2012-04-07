#if SERIES == 5

void flashNuke(const unsigned long int key1, const unsigned long int key2)
{	
	if (key1 == FLASH_KEY1 && key2 == FLASH_KEY2)
	{	
		WDTCTL = WDTPW + WDTHOLD;
		
		while ( (FCTL3 & BUSY) > 0)
		{	
			_no_operation();
		}
		
		FCTL3 = FWPW; /* Clear lock */
		FCTL1 = FWPW + ERASE + MERAS;
		_data16_write_addr(0x08000, 0);
	}
}

unsigned short int flashSegmentErase(const unsigned long int key, unsigned short int segment)
{	
	auto unsigned char wdtstate = WDTCTL_L;
	
	if (key != FLASH_KEY1)
	{	
		return (INVALID_KEY);
	}
	else if ( (FCTL4 & LOCKINFO) > 0)
	{	
		return (SEGMENTS_LOCKED);
	}
	
	WDTCTL = WDTPW + WDTHOLD;
	
	while ( (FCTL3 & BUSY) > 0)
	{	
		_no_operation();
	}
	
	FCTL3 = FWPW; /* Clear lock */
	FCTL1 = FWPW + ERASE; /* Enable segment erase */
	
	switch (segment)
	{	
		case SEGMENT_A:
			
			if ( (FCTL3 & LOCKA) > 0)
			{	
				FCTL3 = FWPW + EMEX; /* Emergency exit */
				return(SEGMENTA_LOCKED);
			}
			else
			{	
				_data16_write_addr(0x019FD, 0);
				break;
			}
			
		case SEGMENT_B:
			
			_data16_write_addr(0x0197D, 0);
			break;
			
		case SEGMENT_C:
			
			_data16_write_addr(0x018FD, 0);
			break;
			
		case SEGMENT_D:
			
			_data16_write_addr(0x0187D, 0);
			break;
			
		default:
			
			FCTL3 = FWPW + EMEX; /* Emergency exit */
			return(INVALID_SEGMENT);
	}
	
	while ( (FCTL3 & BUSY) > 0)
	{	
		_no_operation();
	}
	
	FCTL3 = FWPW + LOCK; /* Lock flash */
	WDTCTL = WDTPW + wdtstate; /* Restore old watchdog state */
	
	if ( (FCTL4 & VPE) > 0)
	{	
		return (VOLTAGE_CHANGE);
	}
	else
	{	
		return (SUCCESS);
	}
}

#endif
