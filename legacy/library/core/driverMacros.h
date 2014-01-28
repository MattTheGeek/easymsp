#ifdef REQUIRE
#	error "REQUIRE is a EasyMSP reserved keyword."
#else
#	define REQUIRE(name) #include "driver/" ##name "/" ##name ".h"
#endif