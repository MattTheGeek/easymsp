/*
 Note: DMA Channel 0 is reserved for system use.
 */

unsigned short int dma 
 
unsigned short int dmaCopy(unsigned long int* source, unsigned long int* dest, unsigned short int count, unsigned short int direction)
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
	
	_data16_write_addr((unsigned short int) &DMA0SA, (unsigned long int) source);
	_data16_write_addr((unsigned short int) &DMA0DA, (unsigned long int) dest);

	DMA0SZ = count;
	
	DMA0CTL |= DMAREQ | DMAEN; /* Start transfer */
	
	DMA0CTL = NULL;
	
	return (0);
}

interrupt void dmaIsr(void)
{
	switch (DMAIV)
}