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

inline unsigned char makePinMask(unsigned short int pin)
{
	if (pin > 88)
	{
		return (0x00);
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

inline unsigned short int makeWordPinMask(unsigned short int pin)
{
	if (pin > 128)
	{
		return (0x0000);
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

