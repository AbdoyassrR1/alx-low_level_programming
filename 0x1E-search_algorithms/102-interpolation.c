#include "search_algos.h"

/**
 * interpolation_search - interpolation_search algorithm
 * @array: pointer to the first element in the array.
 * @size: the size of the array.
 * @value: the target value to be searched.
 *
 * Return: the index of the value if found
 * other wise (-1) if it fails or not found.
*/

int interpolation_search(int *array, size_t size, int value)
{
	int low = 0;
	int high = size - 1;
	int middle;

	if (!array || !value)
	{
		return (-1);
	}
	for ( ; low <= high; )
	{
		middle = low + ((high + low) / (array[high] - array[low]))
		* (value - array[low]);
		if (value > array[middle])
		{
			printf("Value checked array[%d] = [%d]\n", middle, array[middle]);
			low  = middle + 1;
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", middle, array[middle]);
			high = middle - 1;
		}
		if (array[middle] == value)
		{
			return (middle);
		}
	}
	if (array[middle] != value)
	{
		printf("Value checked array[%d] = is out of range\n", middle);
		return (-1);
	}
}
