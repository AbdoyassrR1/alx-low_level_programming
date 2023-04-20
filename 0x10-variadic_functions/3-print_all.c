#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - a function that prints anything
 * @format:a list of types of arguments passed to the function
 * @...: args
 */

void print_all(const char * const format, ...)
{
	int index = 0;
	char *str, *sep = "";

	va_list list;

	va_start(list, format);

	if (format)
	{
		while (format[index])
		{
			switch (format[index])
			{
				case 'c':
					printf("%s%c", sep, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", sep, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", sep, va_arg(list, double));
					break;
				case 's':
					str = va_arg(list, char *);
					if (!str)
						str = "(nil)";
					printf("%s%s", sep, str);
					break;
				default:
					index++;
					continue;
			}
			sep = ", ";
			index++;
		}
	}

	printf("\n");
	va_end(list);
}

int main()
{
	print_all("sifxc", "Abdo", 10, 9.9, 'R');
	return 0;
}
