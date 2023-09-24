#include "sort.h"


/**
 * _swap - swap to element
 * @a: the first element
 * @b: the second element
 *
 * Return: no thing
*/
void swap_(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

/**
 * bubble_sort - bubble_sort algorithm that sort a arr of int
 * @array: the arr to sort
 * @size: size of that array
 *
 * Return: no thing (void)
*/
void bubble_sort(int *array, size_t size)
{
	int swapped = 0;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
	{
    	return;
	}


	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped++;
			}
		}
		if (swapped == 0)
        {
			break;
		}
	}
}
