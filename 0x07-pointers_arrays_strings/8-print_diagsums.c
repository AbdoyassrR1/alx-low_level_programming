#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - Entry point
 * @a: input
 * @size: input
 * Return: Always 0 (Success)
 */
void print_diagsums(int *a, int size)
{
	int s1, s2, z;

	s1 = 0;
	s2 = 0;

	for (z = 0; z < size; z++)
	{
		s1 = s1 + a[z * size + z];
	}

	for (z = size - 1; z >= 0; z--)
	{
		s2 += a[z * size + (size - z - 1)];
	}

	printf("%d, %d\n", s1, s2);
}

