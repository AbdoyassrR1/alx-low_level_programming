#include "lists.h"

/**
 * free_listint - function that frees a listint_t list.
 * @head: ptr to the first element in the list
 * Return: no thing
 */

void free_listint(listint_t *head)
{
    listint_t *ptr;

    while (head)
    {
        ptr = (*head).next;
        free(head);
        head = ptr;
    }
}
