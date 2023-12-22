#include "hash_tables.h"
/**
 * shash_table_create - creates hash table
 * @size: size of the array
 * Return: a pointer to the newly created hash table
 * or NULL if an error occurs
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new;
	unsigned long int i;

	if (size == 0)
		return (NULL);
	new = malloc(sizeof(shash_table_t));
	if (new == NULL)
		return (NULL);
	new->array = malloc(sizeof(shash_node_t *) * size);
	if (new->array == NULL)
	{
		free(new);
		return (NULL);
	}
	new->size = size;
	new->shead = NULL;
	new->stail = NULL;

	for (i = 0; i < size; i++)
		new->array[i] = NULL;
	return (new);
}
/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table to add or update the key/value to
 * @key: The key (string)
 * @value: The value associated with the key (string)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current, *prev;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	index = hash_djb2((unsigned char *)key) % ht->size;

	current = ht->array[index];
	prev = NULL;

	while (current != NULL && strcmp(current->key, key) < 0)
	{
		prev = current;
		current = current->next;
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->next = current;
	if (prev == NULL)
		ht->array[index] = new_node;
	else
		prev->next = new_node;
	if (prev == NULL)
	{
		new_node->snext = ht->shead;
		new_node->sprev = NULL;
		if (ht->shead != NULL)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
		if (ht->stail == NULL)
			ht->stail = new_node;
	}
	else
	{
		new_node->snext = prev->snext;
		new_node->sprev = prev;
		if (prev->snext != NULL)
			prev->snext->sprev = new_node;
		prev->snext = new_node;
		if (new_node->snext == NULL)
			ht->stail = new_node;
	}
	return (1);
}
/**
 * shash_table_get - retrieves a value associated with a key from the hash table
 * @ht: the hash table
 * @key: the key to search for
 * Return: value associated with the key, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int i;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	i = hash_djb2((unsigned char *)key) % ht->size;

	current = ht->array[i];
	while (current != NULL && strcmp(current->key, key) <= 0)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
/**
 * shash_table_print - prints a sorted hash table
 * @ht: sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	for (current = ht->shead; current != NULL; current = current->snext)
	{

			printf("'%s': '%s'", current->key, current->value);
			if (current->snext != NULL)
				printf(", ");
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - print the hash tables key/value pairs in reverse order using the sorted linked list
 * @ht: tha hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	for (current = ht->stail; current != NULL; current = current->sprev)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->sprev != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 * shash_table_delete - deletes a hash table
 * @ht: is the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *next;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			free(current->key);
			free(current->value);

			next = current->next;
			free(current);
			current = next;
		}
	}
	free(ht->array);
	free(ht);
}
