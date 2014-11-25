#ifndef POWER_H
#	define POWER_H

void shutdown();
void reboot();

void setPowerMode(unsigned short int);
unsigned short int getPowerMode();

#	include "power.c"

#endif
