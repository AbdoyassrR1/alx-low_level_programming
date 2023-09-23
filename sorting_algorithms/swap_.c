#include "sort.h"

/**
 * swap - swap to element
 * @a: the first element
 * @b: the second element
 *
 * Return: no thing
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
