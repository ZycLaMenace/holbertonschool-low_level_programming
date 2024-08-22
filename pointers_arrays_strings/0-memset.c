#include "main.h"

/**
 * _memset - fills the memery with b n time
 * @s: pointer to the memory area
 * @b: character to fill in memory
 * @n: The number of bytes to fill
 *
 * Return: pointer to the memory area if success
 *			return 1 if error
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	if (n == 0 || s == NULL)
	{
		return (s);
	}

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
