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
	unsigned int i = 0;
	dlistint_t *bfr_node = *head;
	dlistint_t *temp = *head;

	if (index == 0 && *head)
	{
		if ((*head)->next)
		{
			*head = (*head)->next;
			(*head)->prev = NULL;
			free(temp);
		}

		else
			*head = NULL;
		return (1);
	}

	while (i < index - 1 && bfr_node)
	{
		bfr_node = bfr_node->next;
		i++;
	}

	if (bfr_node)
	{
		temp = bfr_node->next;

		if (temp->next)
			temp->next->prev = bfr_node;
		bfr_node->next = temp->next;
		free(temp);
		return (1);
	}

	return (-1);
}
