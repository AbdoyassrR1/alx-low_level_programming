#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would
 * need to flip to get from one number to another.
 * to get from one number to another
 * @n: num 1
 * @m: num 2
 * Return: number of bits to change.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int index, c = 0;
	unsigned long int curr;
	unsigned long int exclusive = n ^ m;

	for (index = 63; index >= 0; index--)
	{
		curr = exclusive >> index;
		if (curr & 1)
			c++;
	}

	return (c);
}
