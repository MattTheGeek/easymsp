
/*
 *
 * name: fillMemory
 * @param {unsigned short int} dst Starting address to fill
 * @param {unsigned short int} cnt Number of words to fill.
 * @param {unsigned short int} fill Data to fill memory with.
 * @return Nothing
 *
 * Fill memory with the value in fill. Direction is forward (inc).
 *
 * memory[dst ... (dst + cnt)] = fill.
 *
 */

void fillMemory(unsigned short int dst, unsigned short int cnt, unsigned short int fill)
{
	unsigned short int * memptr = dst;

	while (cnt > 0)
	{
		*memptr = fill;
		memptr++;
		cnt--;
	}

	return;
}

/*
 *
 * name: copyMemory
 * @param {unsigned short int} src Starting memory address to copy from.
 * @param {unsigned short int} dst Starting memory address to write to.
 * @param {unsigned short int} cnt The amount of words to transfer.
 * @return Nothing
 *
 * Transfers memory from src to dst by cnt words. Direction is forward (inc).
 *
 */

void copyMemory(unsigned short int src, unsigned short int dst, unsigned short int cnt)
{
	volatile unsigned short int * memptr = src;
	unsigned short int store = 0x0000;

	while (cnt > 0)
	{
		store = *memptr;

		dst++;
		memptr = dst;
		*memptr = store;

		src++;
		memptr = src;
		cnt--;
	}

	return;
}

/*
 *
 * name: detectMemory
 * @param None
 * @return Returns amount of SRAM in the 0x0200 SRAM block in words. Zero either
 * can mean that there really isn't ANY SRAM in the 0x0200h block. When highest
 * 4 bits are set, a failing memory cell was detected in the SRAM array at the
 * address offset stored in the remaining 12 bits.
 *
 * Remember that SRAM on almost* every value line MSP430 MCU starts at address
 * 0x0200.
 *
 * *MSP430G2(7/8/9)55 have extended memory located at 0x1900h. Main SRAM is
 * stored at 0x1100h, and is mirrored at 0x0200.
 *
 */

unsigned short int detectMemory()
{
	const unsigned short int fill = 0x55AA;
	volatile unsigned short int * memptr = 0x0200;

	register unsigned short int memcopy = 0x0000;
	register unsigned short int memres = 0x0000;
	register unsigned short int state = 0x0000;

	do
	{
		memcopy = *memptr;
		*memptr = fill;

			/*
			 * Remark: I can't remember if i'm addressing words or
			 * bytes. So this could cause problems.
			*/
		if (*memptr == fill)
		{
			*memptr = memcopy;

			if (state = 1)
			{
				/*Set highest 4 bits to
				indicate that a bad memory cell was found. */
				memptr |= 0xF000;
				return (memptr - 0x0201);
			}
			else
			{
				memptr++;
			}

			continue;
		}
		else
		{
			*memptr = memcopy;

			if (state = 1)
			{
				memptr = memptr - 2;
			}
			else
			{
				state = 1;
			}

			break;

		}
	}
	while (1);



	return (memptr - 0x0200);
}
