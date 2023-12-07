#include "lists.h"
/**
 * free_dlistint - frees dlistint_t list
 * @head: pointer to the head of doubly linked lists
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *cur = head;
	dlistint_t *next_node;

	while (cur != NULL)
	{
		next_node = cur->next;
		free(cur);
		cur = next_node;
	}
}
