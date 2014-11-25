unsigned short int flashErase(unsigned short int, unsigned short int);
unsigned short int flashEraseSegment(unsigned short int, enum flash_segment);
unsigned short int flashNuke(unsigned short int);

enum flash_segment
{
	INFOA,
	INFOB,
	INFOC,
	INFOD,
	BSL0,
	BSL1,
	BSL2,
	BSL3,
	PROGRAM_MEMORY,
	ALL_BSL,
	ALL_INFO,
	ALL_MEMORY,

};