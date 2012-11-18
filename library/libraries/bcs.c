/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	bcs.c
 *	Basic Clock System Plus (BCS+) library for EasyMSP.   
 *
 *	Part of the EasyMSP Project
 *	www.code.google.com/p/EasyMSP/
 *
 *	Author: Matthew L. Burmeister
 *	Copyright (c) 2010, 2011, 2012 All rights reserved.
 *
 *	Contact
 *		You can contact me by email at matthewburmeister@gmail.com 
 *		or by sending mail to:
 *
 *		Matthew Burmeister
 *		11593 Autunno St
 *		Las Vegas, NV 89183
 *		United States of America
 *
 *	Licence
 *		EasyMSP is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		EasyMSP is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with EasyMSP. If not, see <http://www.gnu.org/licenses/>.
 *
*/

#if (_EM_SERIES == 2) || (_EM_SERIES == 'V') || (defined _EM_HASBCS)

extern unsigned short int setMCLK(unsigned short int source, unsigned short int divider)
{
	switch (source)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	switch (divider)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	return (SUCCESS);
}

extern unsigned short int setSMCLK(unsigned short int source, unsigned short int divider)
{
	switch (source)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	switch (divider)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	return (SUCCESS);
}

extern unsigned short int setACLK(unsigned short int source, unsigned short int divider)
{
	switch (source)
	{
		
		default:
			return (BAD_ARGUMENT);
	}
	
	switch (divider)
	{
		default:
			return (BAD_ARGUMENT);
	}
	
	return (SUCCESS);
}

extern unsigned short int setDCO(unsigned short int mode)
{
	switch (mode)
	{
		case OFF:
			_bic_SR_register(SCG0);
			break;
			
		case ON:
			_bis_SR_register(SCG0);
			break;
			
		case M1:
			
			if ( (CALBC1_1MHZ != 0xFFFF) && (CALDCO_1MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_1MHZ;
				DCOCTL = CALDCO_1MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;		

			
			
		case M8:
			
			if ( (CALBC1_8MHZ != 0xFFFF) && (CALDCO_8MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_8MHZ;
				DCOCTL = CALDCO_8MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;

		case M12:
			

			if ( (CALBC1_12MHZ != 0xFFFF) && (CALDCO_12MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_12MHZ;
				DCOCTL = CALDCO_12MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;

			
		case M16:
			

			if ( (CALBC1_16MHZ != 0xFFFF) && (CALDCO_16MHZ != 0xFFFF) )
			{
				DCOCTL = 0x00;

				BCSCTL1 = CALBC1_16MHZ;
				DCOCTL = CALDCO_16MHZ;
				break;
			}
			else
			{
				return(MISSING_DCOCAL);
			}

			break;

		default:
			return (FAILURE);
	}
	
	return (SUCCESS);
}

#else

#endif
