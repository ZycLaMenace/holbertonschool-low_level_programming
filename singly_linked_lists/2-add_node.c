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
	list_t *new_node;
	char *duplicate;

	new_node = malloc((sizeof(list_t)));
	if (new_node == NULL)
		return (NULL);

	duplicate = strdup(str);
		if (duplicate == NULL)
		{
			free(duplicate);
			return (NULL);
		}
	new_node->str = duplicate;
	new_node->len = strlen(duplicate);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
