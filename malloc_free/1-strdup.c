#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Function that copy a str to a new memory allocated string
 * @str: string to copy
 * @:
 *
 * Return: NULL if str = 0 or fail or pointer.
 */

char *_strdup(char *str)
{
    char *array;
	unsigned int i, len = 0;

if (str == 0)
		return (NULL);

     while (str[len])
        len++;

    array = malloc((len + 1) * sizeof(char));

if (array == NULL)
		return (NULL);

    for (i = 0; i <= len ; i++)
    {
        array[i] = str[i];
    }
    return (array);
}
