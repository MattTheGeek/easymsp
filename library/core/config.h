/*
 *      ___    _    ___ __   __ __  __  ___  ___ 
 *     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
 *     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
 *     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
 * 
 *	config.h
 *	Build time options for EasyMSP.
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


/* 
	-----------------------------------------
	FASTIO
 		Do not let EasyMSP automaticly configure IO pin direction or select bits.
		Setting this option to yes will result in slower and larger code generated
		for all IO operations. 
		
 		However, turning this option off allows you to ignore setting the state
		of a IO pin.
		
		A Example would be reading a pin.
	
		With FASTIO turned on, you would have to manually set the io pin direction.
			
			pinMode(BUTTON, INPUT);
			... readPin(BUTTON);
			
		With FASTIO turned off, EasyMSP will take care of setting direction and other
		option bits as required, and pinMode() would be omitted.
*/	
#		define _EM_FASTIO YES 
/*
		YES - Turn on message output
		NO - Turn off message output
	-----------------------------------------
*/

/*
	-----------------------------------------
	ASCII_LOGO
		Show a ASCII word art logo when compiling in the console output.
      ___    _    ___ __   __ __  __  ___  ___ 
     | __|  /_\  / __|\ \ / /|  \/  |/ __|| _ \
     | _|  / _ \ \__ \ \ V / | |\/| |\__ \|  _/
     |___|/_/ \_\|___/  |_|  |_|  |_||___/|_|  
*/
#		define _EM_ASCII_LOGO YES
/*
		YES - Turn on logo
		NO - Turn off logo
	----------------------------------------- 
*/

/*
	-----------------------------------------
	VERBOSE
		Show EasyMSP messages.
*/
#		define _EM_VERBOSE YES
/*
		YES - Turn on message output
		NO - Turn off message output
	-----------------------------------------
*/

/*
	-----------------------------------------
	EASYTYPES
		Use friendly type names.
		
 		e.g.
			word could be used instead of unsigned short int, byte instead of unsigned char, and boolean instead of bool.
*/
#		define _EM_EASYTYPES YES
/*
		YES - Enable friendly type names.
		NO - Disable friendly type names.
	-----------------------------------------
*/

#		define _EM_PREINIT_VECTORS NO

#		define _EM_SOFTWARE_DELAY NO

#		define _EM_BITMASK_LOOKUP YES
