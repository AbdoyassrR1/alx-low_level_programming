#include "lists.h"

/**
 * print_dlistint - print all element in a doubly linked list.
 * @h: pointer to the first element in the list
 *
 * Return: number of the element
*/

size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;
	const dlistint_t *curr = NULL;

	if (h == NULL)
	{
		return (0);
	}

	curr = h;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		len++;
		curr = curr->next;
	}
	return (len);
}
