#include "port.h"
#include "gpiodef.h"

void pinHigh(unsigned short int);
void pinLow(unsigned short int);

void pinSet(enum port_level, unsigned short int);
void pinMode(enum port_mode, unsigned short int);
void pinState(enum port_level, unsigned short int);

void pinPull(enum port_pull, unsigned short int);

unsigned short int pinRead(unsigned short int);

#include "gpio.c"
#include "gpiosimple.c"
#include "port.c"
