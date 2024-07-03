#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - string return null or the s w/ accept char
 * @s: string
 * @accept: accepted char
 *
 * Return: s 
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		int j = 0;

		while (accept[j])
		{
			if (*s == accept[j])
			{
				return (s);
			}
			j++;
		}

		s++;
	}

	return (NULL);
}
