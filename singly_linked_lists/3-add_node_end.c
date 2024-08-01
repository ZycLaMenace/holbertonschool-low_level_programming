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
	list_t *new = malloc(sizeof(list_t));
	list_t *lastnode = *head;
	int len = 0;

	while (str[len])
		len++;
	if (new == NULL)
		return (NULL);
	new = strdup(str);
		if (new == NULL)
		{
			free(new);
			return (NULL);
		}
	new->len = len;
	new->next = NULL;

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
