/*
	Note: DMA Channel 0 is reserved for system use.
*/

inline void dmainit(void)
{	
	DMACTL4 = DMARMWDIS; /* Let write/read CPU instructions finish before halting for DMA transfer */
}

unsigned short int memcopy(unsigned short int* source, unsigned short int* dest, unsigned short int count, unsigned short int direction)
{
	DMACTL0 &= DMA0TSEL_0; /* Select software trigger */
	
	DMA0CTL = DMADT_1; /* Select block transfer mode */
	
	switch (direction)
	{
		case 0:
			DMA0CTL |= DMADSTINCR_2 | DMASRCINCR_2;
			break;
			
		case 1:
			DMA0CTL |= DMADSTINCR_3 | DMASRCINCR_3;
			break;
			
		default:
			return (1);
	}
	
	DMA0SA = source;
	DMA0DA = dest;
	DMA0SZ = count;
	
	DMA0CTL |= DMAREQ | DMAEN; /* Start transfer */
	
	DMA0CTL = NULL;
	
	return (0);
}