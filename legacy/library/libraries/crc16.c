unsigned short int crcGenerate(unsigned long int* from, unsigned long int* to, unsigned short int seed)
{
	CRCINIRES = seed;
	
	#ifdef HASDMA
		
		DMACTL0 &= DMA0TSEL_0;
		_data16_write_addr((unsigned short int) &DMA0SA, (unsigned long int) from);
		_data16_write_addr((unsigned short int) &DMA0DA, (unsigned long int) to);
		DMA0SZ = ((to - from));
		DMA0CTL = (DMASRCINCR_3 | DMAEN | DMAREQ);
		
	#else
	
		while (from >= to)
		{
			CRCDI = *from;
			from++;
		}
		
	#endif
		
		return (CRCINIRES);
}

unsigned short int crcCompare(unsigned long int* from, unsigned long int* to, unsigned short int seed, unsigned short int crc)
{
	if (calculateCRC(from, to, seed) == crc)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
