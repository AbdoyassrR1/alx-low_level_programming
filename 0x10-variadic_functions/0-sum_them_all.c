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
	va_list args;

	if (!n)
	{
		return (0);
	}

	int s = 0;
	int i = n;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		s += va_arg(args, int);
	}

	va_end(args);
	return (s);

}
