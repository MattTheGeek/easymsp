/* Standard EasyMSP Library */

#ifndef STDINCLUDE_H
#define STDINCLUDE_H

#include "libraries/system.h"
#include "libraries/io.h"
#include "libraries/timer.h"
#include "libraries/watchdog.h"
#include "libraries/flash.h"
#include "libraries/util.h"

#if (defined _EM_HASBCS)
#	include "libraries/bcs.h"
#elif (defined _EM_HASUCS)
#	include "libraries/ucs.h"
#else
#	error "No clock system specified in device header"
#endif


#ifdef _EM_HASUSI
#	include "libraries/usi.h"
#endif

#ifdef _EM_HASUSCI
#	include "libraries/usci.h"
#endif

#ifdef _EM_HASADC10
#	include "libraries/adc10.h"
#endif

#ifdef _EM_HASCOMP
#	include "libraries/comp.h"
#endif

#ifdef _EM_HASPMM
#	include "libraries/pmm.h"
#endif

#ifdef _EM_HASRTC
#	include "libraries/rtc.h"
#endif

#ifdef _EM_HASCRC16
#	include "libraries/crc16.h"
#endif

#ifdef _EM_HASDMA
#	include "libraries/dma.h"
#endif

#ifdef _EM_HASUSB
#	include "libraries/usb.h"
#endif

#include "libraries/io.c"
#include "libraries/system.c"
#include "libraries/timer.c"
#include "libraries/watchdog.c"
#include "libraries/flash.c"
#include "libraries/util.c"

#if (defined _EM_HASBCS)
#	include "libraries/bcs.c"
#elif (defined _EM_HASUCS)
#	include "libraries/ucs.c"
#else
#	error "No clock system specified in device header"
#endif

#ifdef _EM_HASUSI
#	include "libraries/usi.c"
#endif

#ifdef _EM_HASUSCI
#	include "libraries/usci.c"
#endif

#ifdef _EM_HASADC10
#	include "libraries/adc10.c"
#endif

#ifdef _EM_HASCOMP
#	include "libraries/comp.c"
#endif

#ifdef _EM_HASPMM
#	include "libraries/pmm.c"
#endif

#ifdef _EM_HASRTC
#	include "libraries/rtc.c"
#endif

#ifdef _EM_HASCRC16
#	include "libraries/crc16.c"
#endif

#ifdef _EM_HASDMA
#	include "libraries/dma.c"
#endif

#ifdef _EM_HASUSB
#	include "libraries/usb.c"
#endif

/* #include "thread.h" */

#endif
