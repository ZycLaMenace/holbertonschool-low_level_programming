#include "lists.h"
/**
 * add_node - add node
 * @head: head of node
 * @str: str to dupli
 *
 * Return: number of node or null
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc((sizeof(list_t)));
	char *duplicate;

	if (head == NULL || new == NULL)
	{
		free(new);
		return (NULL);
	}

	duplicate = strdup(str);
		if (duplicate == NULL)
		{
			free(duplicate);
			return (NULL);
		}
	new->str = duplicate;
	new->len = _strlen(duplicate);
	new->next = *head;

	*head = new;

	return (new);
}
