#include "main.h"

/**
 * _strcmp - comapre 2 string
 *
 * Return: Always 0 or -number or +number.
 */

int _strcmp(char *s1, char *s2)
{
		while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
