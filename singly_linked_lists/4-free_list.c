#include "lists.h"
/**
 * free_list - function to free every node one by one
 * @head: first node of the list
 *
*/

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
