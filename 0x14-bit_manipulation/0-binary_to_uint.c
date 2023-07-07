#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int.
 * @b: binary number
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int index;
	unsigned int dec = 0;

	if (!b)
		return (0);

	for (index = 0; b[index]; index++)
	{
		if (b[index] < '0' || b[index] > '1')
			return (0);
		dec = 2 * dec + (b[index] - '0');
	}

	return (dec);
}
