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
	size_t low;
	size_t mid;
	size_t high;

	low = 0;
	high = (int) size - 1;

	if (!array || size == 0)
	{
		return (-1);
	}

	while (array[low] != array[high] && value >= array[low] &&
			value <= array[high])
	{
		mid = low + (((double) (high - low) / (array[high] - array[low])) *
					(value - array[low]));

		printf("Value checked array[%ld] = [%d]\n", mid, array[mid]);
		if (value > array[mid])
		{
			low = mid + 1;
		}

		else if (value < array[mid])
		{
			high = mid - 1;
		}

		else
		{
			return (mid);
		}
	}

	mid = low + (((double) (high - low) / (array[high] - array[low])) *
				(value - array[low]));
	printf("Value checked array[%ld] is out of range\n", mid);
	return (-1);
}
