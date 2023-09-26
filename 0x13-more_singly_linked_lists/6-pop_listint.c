#include "lists.h"

/**
  * pop_listint - pops off the head of the list and returns its contents
  * @head: head of the list
  * Return: contents of head
  */
int pop_listint(listint_t **head)
{
	int num;
	listint_t *tmp, *current;

	if (head == NULL)
		return (0);
	tmp = current = *head;

	if (*head)
	{
		num = current->n;
		*head = current->next;
		free(tmp);
	}
	else
		num = 0;
	return (num);
}
