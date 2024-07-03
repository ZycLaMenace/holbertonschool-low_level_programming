#include "main.h"
#include <stddef.h>

/**
 * _strstr - searches a string for any of a set of bytes
 * @haystack: string
 * @needle: substring correspondance
 * Return: substring string
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
