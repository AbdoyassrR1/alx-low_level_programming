#include "main.h"

/**
 * get_endianness - function that checks the endianness.
 * Return: 0 big, 1 little.
 */
int get_endianness(void)
{
	unsigned int index = 1;
	char *ch = (char *) &index;

	return (*ch);
}
