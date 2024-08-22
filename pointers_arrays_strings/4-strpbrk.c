#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the string containing the accepted characters
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 *			or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		int j = 0;

		while (accept[j] != '\0')
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
