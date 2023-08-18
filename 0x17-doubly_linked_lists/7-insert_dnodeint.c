#include "lists.h"

/**
* insert_dnodeint_at_index - Inserts a new node at a given position
* @h: ptr to a pointer to the head node of the list
* @idx: index of the node to insert
* @n: date to store in the new node
*
* Return: ptr to the new node, otherwise NULL
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr = *h;
	dlistint_t *temp;
	unsigned int i = 0;

	temp = malloc(sizeof(dlistint_t));

	if (temp == NULL)
	{
		return (NULL);
	}
	temp->n = n;
	temp->prev = NULL;
	temp->next = NULL;

	if (*h == NULL && idx > 0)
	{
		free(temp);
		return (NULL);
	}

	if (idx == 0)
	{

		temp->next = *h;
		if (*h != NULL)
		{
			(*h)->prev = temp;
		}

		*h = temp;
		return (temp);
	}

	while (curr != NULL && i < idx - 1)
	{
		i++;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		free(temp);
		return (NULL);
	}
	temp->next = curr->next;
	curr->next = temp;
	temp->prev = curr;

	return (temp);
}
