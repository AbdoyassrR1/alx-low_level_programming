#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i = 0;
	hash_table_t *new_hash_table = malloc(sizeof(hash_table_t));

	if (!new_hash_table)
		return (NULL);
	new_hash_table->array = malloc(sizeof(hash_node_t **) * size);
	if (!new_hash_table->array)
	{
		free(new_hash_table);
		return (NULL);
	}
	while (i < size)
	{
		new_hash_table->array[i] = NULL;
		i++;
	}
	new_hash_table->size = size;
	return (new_hash_table);
}
