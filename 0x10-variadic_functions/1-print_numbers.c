#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/***/

void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list arg;
    va_start(arg, n);
    int i;

    for (i = 0 ; i < n ; i++)
    {
        printf("%d",va_arg(arg, int));
    
        if ( i != (n -1) && separator != NULL)
        
            printf("%s", separator);
        
    }
    putchar('\n');

    va_end(arg);
}
