#include "sort.h"

/**
 * _swap - swap to element
 * @a: the first element
 * @b: the second element
 *
 * Return: no thing
*/
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
