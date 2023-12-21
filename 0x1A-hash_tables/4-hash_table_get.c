#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value assocciated  with a key
 * @ht: hash table to look into 
 * @key: key to look for
 * Return: value associated with the element, or NULL
 * if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i;
	hash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	i = key_index((unsigned char *)key, ht->size);
	current = ht->array[i];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
