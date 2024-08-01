#include "lists.h"
/**
 * free_dlistint - function to free every node one by one
 * @head: first node of the list
 *
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->);
		free(temp);
	}
}
