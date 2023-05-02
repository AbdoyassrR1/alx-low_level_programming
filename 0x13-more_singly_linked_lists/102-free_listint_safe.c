#include "lists.h"

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: pointer to the first node
 * Return: the size of the list that was free’d
*/


size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int dif;
	listint_t *ptr;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		dif = *h - (*h)->next;
		if (dif > 0)
		{
			ptr = (*h)->next;
			free(*h);
			*h = ptr;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);

}
