#include "lists.h"

/**
 * listint_len - function that returns the number of elements
 * @h: linked list
 *
 * Return: number of elements.
*/


size_t listint_len(const listint_t *h)
{
	size_t sum = 0;

	while (h)
	{
		sum++;
		h = (*h).next;
	}
	return (sum);
}
