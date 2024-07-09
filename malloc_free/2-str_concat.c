#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Function that concat 2 strg
 * @s1: string 1
 * @s2: string 2
 * Return: s1 followed by s2
 */

char *str_concat(char *s1, char *s2)

{
	char *concat;
	unsigned int i, j, len1 = 0, len2 = 0;

if (s1 == 0)
		s1 = "";
if (s2 == 0)
		s2 = "";

	while (s1[len1])
		len1++;

	while (s2[len2])
		len2++;

concat = malloc((len1 + len2 + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}

	for (j = 0; j < len2; j++, i++)
	{
		concat[i] = s2[j];
	}

	concat[i] = '\0';

	return (concat);
}
