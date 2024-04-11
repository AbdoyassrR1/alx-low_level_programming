#include "search_algos.h"


#include "search_algos.h"

/**
 * interpolation_search - interpolation search algorithm
 * @array: array to be searched in.
 * @size: the size of the array.
 * @value: value to be searched
 *
 * Return: the first index where value is located,
 * -1 other wise
*/

int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (!array || !value)
	{
		return (-1);
	}
	low = 0;
	high = size - 1;
	pos = low + (high - low) / (array[high] - array[low]) * (value - array[low]);
	while (high >= low)
	{
		if (pos > size - 1)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (value == array[pos])
		{
			return (pos);
		}
		else if (value > array[pos])
		{
			low = pos + 1;
			pos = low + (high - low) / (array[high] - array[low])
			 * (value - array[low]);
		}
		else if (value < array[pos])
		{
			high = pos - 1;
			pos = low + (high - low) / (array[high] - array[low])
			 * (value - array[low]);
		}
	}

	return (-1);
}
