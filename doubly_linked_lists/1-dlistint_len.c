#include "lists.h"
/**
 * dlistint_len - function that calcul of lenght of a d linked list
 *@h: head
 *
 * Return: number of element
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
	h = h->next;
	n++;
	}

	return (n);
}
