#include "lists.h"

/**
 * free_listint2 -  function that frees a listint_t list.
 * @head: pointer to the first element in the list
 * Rerurn: nothing
*/


void free_listint2(listint_t **head)
{
	listint_t *ptr;

	while (*head)
	{
		ptr = (*head)->next;
		free(*head);
		*head = ptr;
	}
	*head = NULL;
}
