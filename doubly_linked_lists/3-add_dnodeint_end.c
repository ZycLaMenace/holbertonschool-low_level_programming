#include "lists.h"
/**
 * add_node_end - add node at the end if the list isn't null
 * @head: head of node
 * @str: str to dupli
 *
 * Return: add node end
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *lastnode = *head;
	char *duplicate_str;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	duplicate_str = strdup(str);
		if (duplicate_str == NULL)
		{
			free(duplicate_str);
			return (NULL);
		}

	if (*head == NULL)
		*head = new;
	else
	{
		while (lastnode->next != NULL)
			lastnode = lastnode->next;
		lastnode->next = new;
	}

	return (new);
}
