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
	dlistint_t *curr = *head;
	unsigned int i = 0;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		*head = curr->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(curr);
		return (1);
	}

	while (curr != NULL && i < index - 1)
	{
		i++;
		curr = curr->next;
	}

	if (curr == NULL || curr->next == NULL)
	{
		return (-1);
	}

	curr->next = curr->next->next;
	if (curr->next != NULL)
	{
		curr->next->prev = curr;
	}
	free(curr->next);

	return (1);
}
