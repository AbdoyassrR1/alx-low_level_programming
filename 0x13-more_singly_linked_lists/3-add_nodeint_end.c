#include "lists.h"


/**
 * add_nodeint_end - function that adds a new node at the end.
 * @head: pointer to the first element in the list.
 * @n: data to be add.
 * 
 * Return: the address of the new element, or NULL if it failed
*/



listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *ptr, *temp;
	ptr = head;
	temp = malloc(sizeof(listint_t));

	(*temp).n = n;
	(*temp).next = NULL;

	while ((*ptr).next != NULL){

		ptr = (*ptr).next;
	}
    
	(*ptr).next = temp;

    return (ptr);

}



#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    return (0);
}
