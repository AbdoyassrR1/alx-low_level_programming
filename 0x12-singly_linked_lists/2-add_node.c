#include "lists.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node.
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *nhead = malloc(sizeof(list_t));

	if (!head || !nhead)
		return (NULL);
	if (str)
	{
		nhead->str = strdup(str);
		if (!nhead->str)
		{
			free(nhead);
			return (NULL);
		}
		nhead->len = _strlen(nhead->str);
	}

	nhead->next = *head;
	*head = nhead;
	return (nhead);
}
