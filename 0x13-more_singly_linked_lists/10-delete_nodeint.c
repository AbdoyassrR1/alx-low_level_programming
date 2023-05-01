#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at,
 * index of a listint_t linked list.
 * @head: pointer to the first element in the list
 * @index: he index of the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
*/


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *ptr = *head;
	listint_t *current = NULL;


	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(ptr);
		return (1);
	}

	while (count < index - 1)
	{
		if (!ptr || !(ptr->next))
			return (-1);

		ptr = (*ptr).next;
		count++;
	}

	current = (*ptr).next;
	(*ptr).next = (*current).next;
	free(current);

	return (1);
}
