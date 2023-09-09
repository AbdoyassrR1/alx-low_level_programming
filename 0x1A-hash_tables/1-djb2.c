#include "hash_tables.h"


/**
 * hash_djb2 - function implementing the djb2 algorithm.
 * @str: value
 *
 * Return: the hash number
*/

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int h;
	int count;

	h = 5381;
	while ((count = *str++))
	{
		h = ((h << 5) + h) + count;
	}
	return (h);
}
