#include "main.h"
#include "2-strlen.c"
/**
 * _strcat - concatenates two strings
 *@dest: destiantion string
 *@src: source
 * Return: Always 0.
 */

char *_strcat(char *dest, char *src)
{
	char dest_len = _strlen(dest);
	int i;

   for (i = 0 ; src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

   return dest;
}
