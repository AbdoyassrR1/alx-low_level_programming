#include "hash_tables.h"


/**
 * hash_table_print - function that prints a hash table.
 * @ht: the hash table to be print.
 *
 * Return: no thing
*/

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *box;
	int f = 0;

	if (!ht)
	{
		return;
	}

	printf("{");

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			if (f == 1)
				printf(", ");

			box = ht->array[index];
			while (box != NULL)
			{
				printf("'%s': '%s'", box->key, box->value);
				box = box->next;
				if (box != NULL)
					printf(", ");
			}
			f = 1;
		}
	}
	printf("}\n");

}
