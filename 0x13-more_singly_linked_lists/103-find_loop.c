#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: pointer to the first node
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *sloW = head;
	listint_t *fast = head;

	if (!head)
		return (NULL);

	while (sloW && fast && fast->next)
	{
		fast = fast->next->next;
		sloW = sloW->next;
		if (fast == sloW)
		{
			sloW = head;
			while (sloW != fast)
			{
				sloW = sloW->next;
				fast = fast->next;
			}
			return (fast);
		}
	}

	return (NULL);

}
