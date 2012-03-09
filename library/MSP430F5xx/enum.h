/*
	enum.h	Version 1.0A
	Simple names for functions, modules, etc...
		
	Part of the EasyMSP system
	
	This file is under GPL v3
	Copyright Matthew Burmeister 2012. All Rights Reserved.
	
*/

enum clockSources
{
	XT1CLK = 1,
	VLOCLK = 2,
	REFOCLK = 3,
	DCOCLK = 4,
	XT2CLK = 5
};

enum clock
{
	MCLK = 1,
	SMCLK = 2,
	ACLK = 3,
	MODOSC = 4
};

enum pin
{
	a0 = 0,
	a1 = 1, 
	a2 = 2,
	a3 = 3,
	a4 = 4,
	a5 = 5, 
	a6 = 6,
	a7 = 7,
	a8 = 8,
	a9 = 9,
	a10 = 10,
	a11 = 11,
	a12 = 12,
	a13 = 13,
	a14 = 14,
	a15 = 15,
	
	b0 = 16,
	b1 = 17,
	b2 = 18,
	b3 = 19,
	b4 = 20,
	b5 = 21,
	b6 = 22,
	b7 = 23,
	b8 = 24,
	b9 = 25,
	b10 = 26,
	b11 = 27,
	b12 = 28,
	b13 = 29,
	b14 = 30,
	b15 = 31
	
};

enum divide
{
	by_1 = 			1,
	by_2 = 			2,
	by_4 = 			4,
	by_8 = 			8,
	by_16 = 		16,
	by_32 = 		32,
	by_64 = 		64,
	by_512 = 		512,
	by_8192 = 	8192,
	by_32k = 		32000,
	by_512k = 	512000,
	by_8192k =	8192000,
	by_128m = 	128000000,
	by_2g =    	2000000000
};

enum mul
{
	by_1 = 		1,
	by_2 = 		2,
	by_4 = 		4,
	by_8 = 		8,
	by_16 =	16,
	by_32 =	32
};

enum crystalDriveStrength
{
	upTo8Mhz = 	1,
	upTo16Mhz = 2,
	upTo24Mhz = 3,
	upTo32Mhz = 4
};
	
enum capacitor
{
	
};