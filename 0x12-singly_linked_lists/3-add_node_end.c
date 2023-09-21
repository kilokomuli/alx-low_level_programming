#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to put in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end;
	unsigned int i, count = 0;
	list_t *tmp;


	end = malloc(sizeof(list_t));

	if (end == NULL)
		return (NULL);
	end->str = strdup(str);

	for (i = 0; str[i] != '\0'; i++)
		count++;
	end->len = count;
	end->next = NULL;
	tmp = *head;

	if (tmp == NULL)
		*head = end;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = end;
	}
	return (*head);
}
