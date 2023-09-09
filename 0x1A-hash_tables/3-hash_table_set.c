#include "hash_tables.h"
/**
* hash_table_set -  function that adds an element to the hash table.
* @ht: hash table to add element to
* @key: key to add
* @value: value to add
*
* Return: 1 on success, 0 on failure
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0, i = 0;
	hash_node_t *box = NULL;
	char *value_cpy;

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);
	value_cpy = strdup(value);

	if (!value_cpy)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);

	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_cpy;
			return (1);
		}
	}
	box = malloc(sizeof(hash_node_t));
	if (box == NULL)
		return (0);
	box->key = strdup(key);
	if (box->key == NULL)
	{
		free(box);
		return (0);
	}

	box->value = value_cpy;
	box->next = ht->array[index];
	ht->array[index] = box;
	return (1);
}
