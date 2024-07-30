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
	list_t *new_node_end;
	list_t *tail;
	char *duplicate_str;

	new_node_end = malloc(sizeof(list_t));
	if (new_node_end == NULL)
	{
		return (NULL);
	}
	duplicate_str = strdup(str);
		if (duplicate_str == NULL)
		{
			free(duplicate_str);
			return (NULL);
		}

	if (*head == NULL)
	{
	*head = new_node_end;
	}
	else
	{
		tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new_node_end;
	}

	return (new_node_end);
}
