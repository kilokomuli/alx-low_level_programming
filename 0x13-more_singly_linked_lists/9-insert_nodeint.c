#include "lists.h"

/**
  * insert_nodeint_at_index - insert a node at index
  * @head: head of the list
  * @idx: location to insert node
  * @n: value of the inserted node
  * Return: pointer to head of list
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current, *new_node;

	current = *head;
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = current;
		*head = new_node;
		return (*head);
	}
	while (idx > 1)
	{
		current = current->next;
		idx--;
		if (!current)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
