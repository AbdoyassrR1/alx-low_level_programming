#include "sort.h"


/**
 * bubble_sort - bubble_sort algorithm that sort a arr of int
 * @array: the arr to sort
 * @size: size of that array
 *
 * Return: no thing (void)
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, size2 = size;
	int tmp, f = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size2; j++)
		{
			if (array[j - 1] > array[j])
			{
				f = 1;
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}
		if (f == 0)
			break;
		f = 0;
		size2--;
	}
}
