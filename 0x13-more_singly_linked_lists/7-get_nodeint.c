#include "lists.h"

/***/


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

	if (!ptr)
		return (NULL);
	else
		return (ptr);
}
