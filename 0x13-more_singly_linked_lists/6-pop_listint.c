#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t.
 * @head: pointer to the first element in the list
 * Return:  the head node’s data (n).
*/


int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data;

	if (!head || !*head)
	{
		return (0);
	}

	data = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (data);
}
