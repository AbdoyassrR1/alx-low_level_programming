#include "hash_tables.h"


/**
 * hash_table_create -  function that creates a hash table.
 * @size: the size of the table
 *
 * Return: ptr to the newly hash table
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned long int index;

	hash_table = malloc(sizeof(hash_table_t));


	if (hash_table == NULL)
	{
		return (NULL);
	}
	hash_table->size = size;
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		return (NULL);
	}

	for (index = 0; index < size; index++)
	{
		hash_table->array[index] = NULL;
	}
	return (hash_table);
}
