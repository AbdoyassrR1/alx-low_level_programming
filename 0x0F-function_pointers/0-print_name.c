#include "function_pointers.h"
/**
 * print_name - a function that prints a name.
 *@name: str to add
 *@f:ptr to function.
 *  Return: nothing
 */

 void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
