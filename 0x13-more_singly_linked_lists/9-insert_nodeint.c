#include "lists.h"


/**
 * insert_nodeint_at_index - function that inserts a new node at position.
 * @head: pointer to the first element in the list.
 * @idx: index of the node to insert
 * @n: data to be insert
 *
 * Return: the address of the new node, or NULL if it failed
*/



listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int count = 0;

	listint_t *ptr = *head;

	while (ptr && count < idx)
	{
		ptr = (*ptr).next;
		count++;
	}

	(*ptr).n = n;

	return (ptr ? ptr : NULL);
}
