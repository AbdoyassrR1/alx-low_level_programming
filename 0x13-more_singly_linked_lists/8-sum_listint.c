#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data (n)
 * @head: pointer to the first element in the list.
 * Return: sum of data (n) or 0 if empty list.
*/

int sum_listint(listint_t *head)
{

	listint_t *ptr = head;
	int sum = 0;


	if (!head)
	{
		return (0);
	}

	while (head)
	{
		sum += (*ptr).n;
		ptr = (*ptr).next;
	}

	return (sum);
}
