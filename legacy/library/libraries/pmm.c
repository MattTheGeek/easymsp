/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	pmm.c
 *	Power Management Module (PMM) library for EasyMSP.   
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

unsigned short int pmmSecured(void)
{
	if ((SYSCTL & SYSPMMPE) > 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}	
}

unsigned short int pmmUnlock(void)
{
	if (pmmSecured())
	{
		return (FAILURE);
	}
	else
	{
		PMMCTL_H = PMMPW;
		return (SUCCESS);
	}
}

void pmmLock(void)
{
	PMMCTL_H = 0x00;
	return;
}

void pmmSecure(void)
{
	SYSCTL |= SYSPMMPE;
	return;
}

unsigned short int svsDisable(unsigned short int side)
{
	if (pmmUnlock())
	{
		return (FAILURE);
	}
	
	switch (side)
	{
		case LOW:
			SVSMLCTL &= ~SVSLE;
			break;
			
		case HIGH:
			SVSMHCTL &= ~SVSHE;
			break;
			
		default:
			return (FAILURE);
	}
	
	return (SUCCESS);
}

unsigned short int svmDisable(unsigned short int side)
{
	if (pmmUnlock())
	{
		return (FAILURE);
	}
	
	switch (side)
	{
		case LOW:
			SVSMLCTL &= ~SVMLE;
			break;
			
		case HIGH:
			SVSMHCTL &= ~SVMHE;
			break;
			
		default:
			return (FAILURE);
	}
	
	return (SUCCESS);
}

unsigned short int setCPUVoltage(unsigned short int level)
{

	if (ppmSecured())
	{
		return (FAILURE);
	}
	
	switch (level)
	{
		case 0:
			PMMCTL0 = PMMPW + (PMMCTL0_L & PMMCOREV_0);
		break;
		
		case 1:
			PMMCTL0 = PMMPW + (PMMCTL0_L | PMMCOREV_1);
		break;
		
		case 2:
			PMMCTL0 = PMMPW + (PMMCTL0_L | PMMCOREV_2);
		break;
	
		case 3:
			PMMCTL0 = PMMPW + (PMMCTL0_L | PMMCOREV_3);
		break;
		
		default:
		
		break;
	}
}
		
void issuePOR(void)
{
	if (pmmSecured)
	{
		/* We have to resort to a dirty way of issuing a POR */
	}
	else
	{
		PMMCTL0 = PMMPW + PMMSWPOR;
	}
}

void issueBOR(void)
{
	PMMCTL0 = PMMPW + PMMSWBOR;
}
