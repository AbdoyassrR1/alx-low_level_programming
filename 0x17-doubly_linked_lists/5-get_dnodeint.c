#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns the nth node of a linked list
 * @head: ptr to the first element in the list
 * @index: index of the list
 *
 * Return: returns the nth node of a linked list
*/


dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t i = 0;
	dlistint_t *curr;

	curr = head;

	if (head == NULL)
	{
		return (NULL);
	}


	while (curr != NULL)
	{
		if (i == index)
		{
			return (curr->n);
		}
		else
		{
			curr = curr->next;
			i++;
		}
	}
}
