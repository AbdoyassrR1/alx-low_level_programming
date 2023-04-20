#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - a function that prints anything
 * @format:a list of types of arguments passed to the function
 * @c : char
 * @i : integer
 * @f : float
 * @s : string
 * any other char should be ignored.
 * Return: void
*/

void print_all(const char* const format, ...)
{
    const char* p = format;
    va_list arg;
    va_start(arg, format);

    char c;
    int i;
    float f;
    char* s;

    while (*p != '\0') {
        switch (*p) {
            case 'c':
                c = va_arg(arg, int);
                printf("%c", c);
                break;

            case 'i':
                i = va_arg(arg, int);
                printf("%d", i);
                break;

            case 'f':
                f = va_arg(arg, double);
                printf("%f", f);
                break;

            case 's':
                s = va_arg(arg, char*);
                if (s == NULL) {
                    printf("(nil)");
                } else {
                    printf("%s", s);
                }
                break;

            default:
                break;
        }
        p++;
        if (*p != '\0') {
            printf(", ");
        }
    }
    printf("\n");
    va_end(arg);
}
