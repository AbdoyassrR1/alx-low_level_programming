#include "lists.h"

/**
 * free_dlistint - free linked list
 * @head: ptr to the first element in the list
 *
 * Return: no thing
*/
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	{
		return (0);
	}
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);

}
