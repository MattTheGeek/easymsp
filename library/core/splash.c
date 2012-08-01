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
		asm("	.mmsg 	\"Version 1.0.0.RC	\"");
		asm("	.mmsg	\"EasyMSP is compiling...\"");
#	endif /* _EM_VERBOSE */
#endif /* __EASYMSP__ */
