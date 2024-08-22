#include "main.h"

/**
 * _memcpy - copy memory src to dest
 * @dest: pointer to the destination memory area
 * @src: pointer to the source memory area from which the data is to be copied
 * @n: number of bytes to be copied
 *
 * Return: pointer to the destination memory area
 */

char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	if (n == 0 || dest == NULL || src == NULL)
	{
		return (dest);
	}

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
