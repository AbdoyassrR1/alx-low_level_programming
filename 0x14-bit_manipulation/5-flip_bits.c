#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would,
 * need to flip to get from one number to another.
 * @n: first num
 * @m: sec nun
 * Return: number of bits to change
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, counter = 0;
	unsigned long int curr;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		curr = exclusive >> i;
		if (curr & 1)
			counter++;
	}

	return (counter);

}
