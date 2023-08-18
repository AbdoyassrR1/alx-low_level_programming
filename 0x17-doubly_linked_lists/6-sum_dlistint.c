#include "lists.h"

/**
 * sum_dlistint - function that returns the sum of
 * all the data (n) of a linked list.
 * @head: ptr to the first element in the list
 *
 * Return: sum all date
*/

int sum_dlistint(dlistint_t *head)
{
	int sum;

	for (sum = 0; head != NULL;)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
