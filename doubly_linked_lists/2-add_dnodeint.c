#include "lists.h"
/**
 * add_dnodeint - add node at beginning
 * @head: the list
 * @n: the value
 *
 * Return: the node or null
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));
	dlistint_t *last_node;

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new;
		new->prev = last_node;
	}

	return (new);
}
