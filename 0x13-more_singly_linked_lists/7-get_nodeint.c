#include "lists.h"

/***/


listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count;
	count = 0;
	listint_t *ptr;
	ptr = head;


	while (ptr && count > index)
	{
		count++;
		ptr = (*ptr).next;
	}

	if (index > (count -1))
		return (NULL);

	return (ptr);
}
