#include "lists.h"
/**
 * print_dlistint - function that prints all the elements of a list_t list.
 *@h: head of the list
 *
 * Return: number of node
 */

size_t print_dlistint(const dlistint_t *h)
{
	int count = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
	printf("[%d] %s\n", h->n, h->next);
	h = h->next;
	count++;
	}
	return (count);
}
