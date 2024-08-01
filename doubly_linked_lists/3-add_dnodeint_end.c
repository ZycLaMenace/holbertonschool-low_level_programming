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
	int len = 0;

	if (head == NULL || new == NULL)
		return (NULL);
	while (new->next != head)
	new->n = n;
	new->next = 


	return (new);
}
