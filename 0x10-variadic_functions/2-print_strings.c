#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/***/

void print_strings(const char *separator, const unsigned int n, ...)
{
    va_list arg;
	unsigned int i;

	va_start(arg, n);

	for (i = 0 ; i < n ; i++)
	{
		printf("%d", va_arg(arg, int));

		if (i != (n - 1) && separator != NULL)

			printf("%s", separator);

	}
	printf("\n");
}
