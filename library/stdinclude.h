/* Standard EasyMSP Library */

#ifndef STDINCLUDE_H
#define STDINCLUDE_H

#include "libraries/io.h"
#include "libraries/system.h"
#include "libraries/timer.h"
#include "libraries/watchdog.h"
#include "libraries/flash.h"

#ifdef HASBCS
#include "libraries/bcs.h"
#endif

#ifdef HASUCS
#include "libraries/ucs.h"
#endif

#ifdef HASUSI
#include "libraries/usi.h"
#endif

#ifdef HASUSCI
#include "libraries/usci.h"
#endif

#ifdef HASADC10
#include "libraries/adc10.h"
#endif

#ifdef HASCOMP
#include "libraries/comp.h"
#endif

#ifdef HASPMM
#include "libraries/pmm.h"
#endif

#ifdef HASRTC
#include "libraries/rtc.h"
#endif

#ifdef HASCRC16
#include "libraries/crc16.h"
#endif

#ifdef HASDMA
#include "libraries/dma.h"
#endif

#ifdef HASUSB
#include "libraries/usb.h"
#endif

#include "libraries/io.c"
#include "libraries/system.c"
#include "libraries/timer.c"
#include "libraries/watchdog.c"
#include "libraries/flash.c"

#ifdef HASBCS
#include "libraries/bcs.c"
#endif

#ifdef HASUCS
#include "libraries/ucs.c"
#endif

#ifdef HASUSI
#include "libraries/usi.c"
#endif

#ifdef HASUSCI
#include "libraries/usci.c"
#endif

#ifdef HASADC10
#include "libraries/adc10.c"
#endif

#ifdef HASCOMP
#include "libraries/comp.c"
#endif

#ifdef HASPMM
#include "libraries/pmm.c"
#endif

#ifdef HASRTC
#include "libraries/rtc.c"
#endif

#ifdef HASCRC16
#include "libraries/crc16.c"
#endif

#ifdef HASDMA
#include "libraries/dma.c"
#endif

#ifdef HASUSB
#include "libraries/usb.c"
#endif

//#include "thread.h"

#endif
