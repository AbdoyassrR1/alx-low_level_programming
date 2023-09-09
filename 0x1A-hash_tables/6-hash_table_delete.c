#include "hash_tables.h"


/**
 * hash_table_delete - function that deletes a hash table.
 * @ht: the hash table to be delete
 *
 * Return: no thing (void)
*/

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *temp, *next;
	hash_table_t *head = ht;

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			temp = ht->array[index];
			while (temp != NULL)
			{
				next = temp->next;
				free(temp->key);
				free(temp->value);
				free(temp);
				temp = next;
			}
		}
	}

	free(head->array);
	free(head);
}
