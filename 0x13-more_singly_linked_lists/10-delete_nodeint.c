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
	listint_t *currunt;


	if (!head)
	{
		return (-1);
	}

	while (ptr && count < index)
	{
		ptr = (*ptr).next;
		count++;
	}
	(*currunt).next = ptr;
	ptr = (*ptr).next;
	free(currunt);

	return (1);
}
