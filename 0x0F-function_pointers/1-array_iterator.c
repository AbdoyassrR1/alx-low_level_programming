#include "function_pointers.h"

/**
 * array_iterator -  a function that executes a function 
 *@array:QQQ
 *@size:QQQ
 *@action:QQQ
 * Return: nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (array && size && action)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i];)
		}
	}
}
