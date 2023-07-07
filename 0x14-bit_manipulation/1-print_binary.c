#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number.
 * @n: number.
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int index, count = 0;
	unsigned long int curr;

	for (index = 63; index >= 0; index--)
	{
		curr = n >> index;

		if (curr & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
