#include "main.h"
#include "2-strlen.c"

/** 
 * _strncat - concatenates two strings
 *@dest: destiantion string
 *@src: source
 * Return: Always 0.
 */

char *_strncat(char *dest, char *src, int n)
{
	char dest_len = _strlen(dest);
	int i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
	{
	dest[dest_len + i] = src[i];
	}
	return (dest);
}
