/*
 * crc16.h
 *
 *  Created on: Mar 11, 2012
 *      Author: Matthew
 */

#ifndef CRC16_H_
#define CRC16_H_

unsigned short int calculateCRC(unsigned long int* from, unsigned long int* to, unsigned short int seed);
unsigned short int compareCRC(unsigned long int* from, unsigned long int* to, unsigned short int seed, unsigned short int crc);

#endif /* CRC16_H_ */
