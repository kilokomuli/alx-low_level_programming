#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes the node at index index of
 * a dlistint_t linked list.
 * @head: pointer to th ehead of doubly linked list
 * @index: index of the node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *next_node;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		next_node = (*head)->next;
		if (next_node != NULL)
			next_node->prev = NULL;
		free(*head);
		*head = next_node;

		return (1);
	}
	current = *head;
	while (current != NULL && index > 0)
	{
		current = current->next;
		index--;
	}
	if (current == NULL)
		return (-1);
	if (current->prev != NULL)
		current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
	return (1);
}
