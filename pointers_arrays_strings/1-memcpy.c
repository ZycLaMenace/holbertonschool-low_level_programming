#include "main.h"

/**
 * _memcpy - copy memory
 *@n: byte
 *@dest: destination
 *@src: source
 * Return: pasted memory
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
