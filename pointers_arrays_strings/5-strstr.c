#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @haystack: string
 * @needle: substring correspondance
 *
 * Return: s that matches one of the bytes in accept or if there is nothing NULL
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		int i = 0;
		int j = 0;

		while (needle[j] && haystack[i] == needle[j])
		{
			i++;
			j++;
		}

		if (needle[j] == '\0')
		{
			return (haystack);
		}

		haystack++;
	}
	return (NULL);
}
