#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - a function that prints strings, followed by a new line.
 * @separator: separator.
 * @n: number of args
 * Return: no thing
*/

void print_strings(const char *separator, const unsigned int n, ...)
{
	int i = n;
	char *string;
	va_list arg;

	if (!n)
	{
		putchar('\n');
		return;
	}
	va_start(arg, n);
	while (i--)
	{
		printf("%s%s", (string = va_arg(arg, char *)) ? string : "(nil)",
		i ? (separator ? separator : "") : "\n");
	}
	va_end(arg);

}
