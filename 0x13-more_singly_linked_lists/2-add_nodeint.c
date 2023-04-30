#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the beginning of a list.
 * @head: ptr to the first element in the list
 * @n: data to be add.
 *
 * Return: he address of the new element, or NULL if it failed
*/



listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;

	node = malloc(sizeof(listint_t));

	if (!node)
	{
		return (NULL);
	}

	(*node).n = n;
	(*node).next = *head;
	*head = node;

	return (node);
}
