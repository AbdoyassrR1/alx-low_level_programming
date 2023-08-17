#include "lists.h"


/**
 * dlistint_len - returns the number of elements in a linked list
 * @h: pointer to the first element in the list
 *
 * Return: the number of elements in a linked list
*/

size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	if (h == NULL)
	{
		return (0);
	}

	while (h != NULL)
	{
		len++;
		h = h->next;
	}

	return (len);

}
