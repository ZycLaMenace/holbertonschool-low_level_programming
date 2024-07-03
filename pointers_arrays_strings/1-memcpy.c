#include "main.h"

/**
 * _memcpy - copy memory
 *@n: byte
 *@dest: destination
 *@src: source
 * Return: memory area, a pointer to the memory area s
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char tmp;

	for (i = 0; i < n; i++)
	{
		tmp = src[i];
		dest[i] = tmp;
	}
	return (dest);
}
