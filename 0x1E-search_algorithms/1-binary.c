#include "search_algos.h"

/**
 * binary_search - binary search algorithm
 * @array: array to be searched in.
 * @size: the size of the array.
 * @value: value to be searched
 *
 * Return: the first index where value is located,
 * -1 other wise
*/

int binary_search(int *array, size_t size, int value)
{
	size_t low, high, index;
	int middle;

	if (!array || !value)
	{
		return (-1);
	}
	low = 0;
	high = size - 1;
	middle = (low + high) / 2;
	while (high >= low)
	{
		printf("Searching in array: ");
		for (index = low; high >= index; index++)
		{
			if (index == high)
			{
				printf("%d\n", array[index]);
			}
			else
			{
				printf("%d, ", array[index]);
			}
		}
		if (value == array[middle])
		{
			return (middle);
		}
		if (value > array[middle])
		{
			low = middle + 1;
			middle = (low + high) / 2;
		}
		else if (value < array[middle])
		{
			high = middle - 1;
			middle = (low + high) / 2;
		}
	}
	return (-1);
}
