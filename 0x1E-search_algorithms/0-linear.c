#include "search_algos.h"

/**
 * linear_search - linear search algorithm
 * @array: array to be searched in.
 * @size: the size of the array.
 * @value: value to be searched
 *
 * Return: the first index where value is located,
 * -1 other wise
*/

int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (!array || !value)
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
