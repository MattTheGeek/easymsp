unsigned short int calculateCRC(unsigned short int* from, unsigned short int* to, unsigned short int seed);
inline unsigned short int compareCRC(unsigned short int* from, unsigned short int* to, unsigned short int seed, unsigned short int crc);

unsigned short int calculateCRC(unsigned short int* from, unsigned short int* to, unsigned short int seed)
{
	CRCINIRES = seed;
	
	#ifdef HASDMA
		
		DMACTL0 &= DMA0TSEL_0;
		DMA0SA = from;
		DMA0DA = &CRCDI;
		DMA0SZ = (to - from);
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

inline unsigned short int compareCRC(unsigned short int* from, unsigned short int* to, unsigned short int seed, unsigned short int crc)
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