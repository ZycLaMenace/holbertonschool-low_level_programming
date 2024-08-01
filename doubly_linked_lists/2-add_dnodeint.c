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
	dlistint_t *new = malloc((sizeof(dlistint_t)));

	if (head == NULL || new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	*head = new;

	return (new);
}
