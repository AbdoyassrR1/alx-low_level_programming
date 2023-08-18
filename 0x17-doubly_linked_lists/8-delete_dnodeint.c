#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a linked list.
 * @head: ptr the list
 * @index: index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed.
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int dist = 0;

	/* Handle an empty list */
	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return (1);
	}

	while (current != NULL && dist < index - 1)
	{
		dist++;
		current = current->next;
	}

	if (current == NULL || current->next == NULL)
	{
		return (-1);
	}

	current->next = current->next->next;
	if (current->next != NULL)
	{
		current->next->prev = current;
	}
	free(current->next);

	return (1);
}
