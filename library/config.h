/*
	config.h
	Build Time settings for EasyMSP
	
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
#		define FASTIO YES 
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
#		define ASCII_LOGO YES
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
#		define VERBOSE YES
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
#		define EASYTYPES YES
/*
		YES - Enable friendly type names.
		NO - Disable friendly type names.
	-----------------------------------------
*/

#		define PREINIT_VECTORS NO

#		define SOFTWARE_DELAY NO
