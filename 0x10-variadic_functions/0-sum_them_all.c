#include "variadic_functions.h"
#include <stdarg.h>

/**
* sum_them_all - a function that returns the sum of all its parameters.
* @n: number of args
* @... :args
* Return: s
*/

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	int i = n;
	va_list args;

	if (n == 0)
	{
		return (0);
	}

	va_start(args, n);
	while (i--)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return (sum);
}
