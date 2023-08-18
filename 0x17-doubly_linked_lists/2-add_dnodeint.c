#include "lists.h"


/**
 * add_dnodeint - function that adds a new node at the beginning of a list.
 * @head: ptr to the first element in the list
 * @n: data to be insert
 *
 * Return: ptr to the head of a list
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *temp = malloc(sizeof(dlistint_t));

	if (*head == NULL)
	{
		temp->n = n;
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		 temp->n = n;
		 temp->next = *head;
		 temp->prev = NULL;
		 (*head)->prev = temp;
		 *head = temp;
	}
	return (temp);

}
