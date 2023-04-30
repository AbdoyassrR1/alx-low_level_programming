#include "lists.h"

/**
 * add_nodeint_end - function that adds a new node at the end.
 * @head: pointer to the first element in the list.
 * @n: data to be add.
 * Return: the address of the new element, or NULL if it failed
*/


listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node;
	listint_t *ptr;

	ptr = head;

	node = malloc(sizeof(listint_t));

	if (!node)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	while (ptr->next)
		ptr = ptr->next;

	ptr->next = node;

	return (node);
}
