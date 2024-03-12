#include "search_algos.h"

/**
 * linear_search - linear_search algorithm
 * @array: pointer to the first element of the array.
 * @size: the size of the array.
 * @value: the  value to search for in the array.
 *
 * Return: the index of value other wise  -1 if not found.
*/



int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (!array | !value)
	{
		return (-1);
	}

	for (index = 0; index < size; index++)
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		if (array[index] == value)
		{
			return (index);
		}
	}
	return (-1);
}
