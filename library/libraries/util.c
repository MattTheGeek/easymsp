/*
 * util.c
 * Version: 1.0.0
 * Library for useful functions
 *
 * Author: Matthew Burmeister
 * Copyright Matthew Burmeister 2012. All Rights Reserved.
 *
 * Part of the EasyMSP Project.
 *
 */

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



 
unsigned char getBitMask(unsigned short int bit)
{
	if (bit < 8)
	{
#if (_EM_BITMASK_LOOKUP == YES)
		return ( bitmaskLookup[bit] );
#else
		return ( (1 << bit) );
#endif
	}
	else
	{
		return ( NULL );
	}
}


unsigned short int getWordBitMask(unsigned short int bit)
{
#if (_EM_BITMASK_LOOKUP == YES)	/* Is generating bitmasks through a lookup table enabled? */

	if (bit < 8)
	{
		return ( bitmaskLookup[bit] );
	}
	else if (bit < 16)
	{
		return ( ( (bitmaskLookup[bit]) << 8 ) );
	}
	else
	{
		return (NULL);
	}
	
#else
	
	if (bit < 16)
	{
		return ( 1 << bit );
	}
	else
	{
		return (NULL);
	}
	
#endif
}

unsigned char makePinMask(unsigned short int pin)
{
	if (pin > 88)
	{
		return (NULL);
	}
	else
	{
		do
		{
			pin -= 8;
		}
		while (pin <= 7);
	
		return (1 << pin);
	}
}

unsigned short int makeWordPinMask(unsigned short int pin)
{
	if (pin > 128)
	{
		return (NULL);
	}
	else
	{
		do
		{
			pin -= 16;
		}
		while (pin <= 15);
				
		return (1 << pin);
	}
}

