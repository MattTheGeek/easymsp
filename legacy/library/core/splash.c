/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	splash.c
 *	Build console ascii logo. 
 *  
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

#ifdef __EASYMSP__
#	if (_EM_ASCII_LOGO == YES) && (_EM_VERBOSE == YES)
		/* EasyMSP ASCII art logo */
		asm("   .mmsg   \" ___    _    ___ __   __ __  __  ___  ___  \"");
		asm("   .mmsg   \"| __|  /_\\  / __|\\ \\ / /|  \\/  |/ __|| _ \\ \"");
		asm("   .mmsg   \"| _|  / _ \\ \\__ \\ \\ V / | |\\/| |\\__ \\|  _/ \"");
		asm("	.mmsg	\"|___|/_/ \\_\\|___/  |_|  |_|  |_||___/|_|   \"");
#	else
		asm("	.mmsg	\"EasyMSP\"");
#	endif /* _EM_ASCII_LOGO */
#	if (_EM_VERBOSE == YES)
		asm("	.mmsg	\"Copyright (c) 2010 - 2012 Matthew L. Burmeister. All Rights Reserved\"");
		asm("	.mmsg 	\"Version 1.0.2	\"");
		asm("	.mmsg	\"EasyMSP is compiling...\"");
#	endif /* _EM_VERBOSE */
#endif /* __EASYMSP__ */
