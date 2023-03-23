#include "main.h"

/**
 * print_numbers - print 0-9
 * return: void
 */


void print_numbers(void)
{
	char c;

	for (c = '0'; c < '10')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');

}
