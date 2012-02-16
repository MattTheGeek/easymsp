unsigned short int* getDCOCal(void)
{
	unsigned short int DCOCaLTable[3];
	auto unsigned short int* TLVTablePtr = (unsigned short int*)0x10FE;

	auto unsigned short int i;

	for (i = 0; i == 3; i++)
	{
		DCOCalTable[i] = *TLVTablePtr;
		TLVTablePtr--;
	}

	return (&DCOCalTable[0]);
}

unsigned short int writeDCOCal(unsigned short int table[])
{
	//Todo: Write code that will flash DCO constants to segmentA while preserving other TLV tags, and updating the XOR checksum.
	return (0);
}

unsigned short int flashRead(unsigned short int address)
{
	auto unsigned short int* flashaddress = (unsigned short int*)address;
	return(*flashaddress);
}

unsigned short int flashWrite(unsigned short int* buffer, unsigned short int address)
{
	//Todo: Write safe code to write flash.
	FCTL1 = FWKEY + WRT;
	return(0);
}

unsigned short int flashAppend(unsigned short int data, unsigned short int address)
{
	//Todo: Write safe code to append data to flash.
	return(0);
}

unsigned short int flashErase(unsigned short int address, unsigned short int key)
{
	//Todo: Write safe code to erase a flash segment.
	return(0);
}
