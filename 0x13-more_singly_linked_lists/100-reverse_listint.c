#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list.
 * @head: pointer to the first element in the list
 * Return: a pointer to the first node of the reversed list
*/

// first we need to ptr to point to the sec node of the list
// sec update the first node to NULL
// set the temp to point to first node
// move the head to sec node 
// end the loop when head == NULL

listint_t *reverse_listint(listint_t **head)
{
    listint_t *next = NULL;
    listint_t *prev = NULL;

    while (head != NULL)
    {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }
    *head = prev;
    return (*head); 
}
