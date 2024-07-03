#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string 
 * @accept: accepted char
 *
 * Return: s that matches one of the bytes in accept or if there is nothing NULL
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
