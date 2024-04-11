#include "search_algos.h"


/**
 * jump_search - jump search algorithm
 * @array: array to be searched in.
 * @size: the size of the array.
 * @value: value to be searched
 *
 * Return: the first index where value is located,
 * -1 other wise
*/


int jump_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t jump = sqrt(size);
	size_t high = jump;
	size_t index;

	if (!array || !value || size == 0)
	{
		return (-1);
	}
	printf("Value checked array[%ld] = [%ld]\n", low, low);
	while (value > array[high] && low < size)
	{
		low = high;
		high += jump;
		printf("Value checked array[%ld] = [%ld]\n", low, low);
		if (high > size -1)
		{
			high = size;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n", low, high);
	for (index = low; index <= high; index++)
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		if (array[index] == value)
		{
			return (index);
		}
	}
	return (-1);
}
