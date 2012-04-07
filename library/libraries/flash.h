/*
 *
 *
 *
 *
 *
 *
 *
 *
 */

#ifndef __EASYMSP__
#	 error "Module flash requires EasyMSP."
#endif

#ifndef FLASH_H
#define FLASH_H

unsigned short int flashSegmentErase(const unsigned long int key, unsigned short int segment);
void flashNuke(const unsigned long int key1, const unsigned long int key2);

#endif
