#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: pointer to list
 * @idx: index of inserting position
 * @n: data for new node insertion
 *
 * Return: the address of the new node
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int index = 0;
	dlistint_t *new = malloc(sizeof(dlistint_t)), *tmp = *h;

	if (new)
	{
		new->n = n;
		if (idx == 0)
		{
			if (*h)
			{
				new->next = *h;
				(*h)->prev = new;
			}
			*h = new;
			return (new);
		}
		while (index < idx - 1 && tmp)
		{
			tmp = tmp->next;
			index++;
		}
		if (tmp)
		{
			if (tmp->next)
				tmp->next->prev = new;
			new->next = tmp->next;
			new->prev = tmp;
			tmp->next = new;
			return (new);
		}
	}
	return (NULL);
}
