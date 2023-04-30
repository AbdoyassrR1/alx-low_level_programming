#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node
 * @head: pointer to the first element in the list
 * @index: index of the node to return
 * Return: returns the nth node
*/


listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count;

	count = 0;
	listint_t *ptr;

	ptr = head;

	while (ptr && count < index)
	{
		ptr = (*ptr).next;
		count++;
	}

	return (ptr ? ptr : NULL);
}
