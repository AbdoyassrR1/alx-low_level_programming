#include "lists.h"


/**
 * add_dnodeint_end - add a new node at the end of doubly linked list
 * @head: pointer to the first element in the list
 * @n: the data to be insert
 *
 * Return: ptr to the first element in the list
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp = malloc(sizeof(dlistint_t));

	if (!temp)
	{
		return (NULL);
	}

	if (*head == NULL)
	{
		temp->n = n;
		temp->prev = NULL;
		temp->next = NULL;
		*head = temp;
	}
	else
	{
		temp->n = n;
		temp->next = NULL;
		while ((*head)->next != NULL)
		{
			(*head) = (*head)->next;
		}
		temp->prev = *head;
		(*head)->next = temp;
	}
	return (temp);
}
