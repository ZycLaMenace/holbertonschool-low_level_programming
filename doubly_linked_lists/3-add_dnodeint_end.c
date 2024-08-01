#include "lists.h"
/**
 * add_dnodeint_end - add node at the end if the list isn't null
 * @head: head of node
 * @n: the value
 *
 * Return: add node end
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
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
