#include <stdio.h>

/**
 * _strstr - locates a substring
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: a pointer to the beginning of the located substring,
 *         or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		int i = 0;
		int j = 0;

		while (needle[j] != '\0' && haystack[i] == needle[j])
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
