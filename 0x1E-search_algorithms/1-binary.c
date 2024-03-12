#include "search_algos.h"


/**
 * binary_search - binary_search algorithm.
 * @array: pointer to the first element of the array.
 * @size: the size of the array.
 * @value: the value to be searched.
 *
 * Return: the index of value other wise -1 if not found.
*/
int binary_search(int *array, size_t size, int value)
{
	int low = 0;
	int high = size - 1;
	int middle;

	if (!array || !value)
	{
		return (-1);
	}
	for ( ; array[middle] != value; )
	{
		middle = (low + high) / 2;
		print_arr_at_index(array, low, high);
		if (value > array[middle])
		{
			low  = middle + 1;
		}
		else
		{
			high = middle - 1;
		}
		if (array[middle] == value)
		{
			return (middle);
		}
	}
	return (-1);
}



/**
 * print_arr_at_index - print array
 * @array: pointer to the array to be printed.
 * @high: last element
 * @low: first element
 *
 * Return: no thing (void)
*/
void print_arr_at_index(int *array, int low, int high)
{
	printf("Searching in array: ");
	for ( ; high + 1 > low ;)
	{
		if (high == low)
		{
			printf("%d", array[low]);
			printf("\n");
			return;
		}
		else
		{
		printf("%d, ", array[low]);
		low++;
		}
	}
	printf("\n");

}
