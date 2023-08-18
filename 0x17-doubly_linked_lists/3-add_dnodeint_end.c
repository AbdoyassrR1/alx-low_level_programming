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
	dlistint_t *curr;

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
		curr = *head;
		temp->n = n;
		temp->next = NULL;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		temp->prev = curr;
		curr->next = temp;
	}
	return (temp);
}
