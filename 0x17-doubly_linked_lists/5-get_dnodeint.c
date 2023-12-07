#include "lists.h"
/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to head of the double linked list
 * @index: index of the node starting from 0
 * Return: the node at the desired index
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *cur = head;

	while (cur != NULL && index > 0)
	{
		cur = cur->next;
		index--;
	}
	if (cur == NULL)
		return (NULL);
	return (cur);
}
