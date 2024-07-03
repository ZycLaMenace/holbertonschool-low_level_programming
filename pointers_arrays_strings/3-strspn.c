#include "main.h"

/**
 * _strspn - search accepted char in string
 * @s: string
 * @accept: accepted char
 *
 * Return: number of accepted char in string
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;

	while (*s)
	{
		int j = 0;

		while (accept[j])
		{
			if (*s == accept[j])
			{
				j = -1;
				break;
			}
			j++;
		}

		if (j != -1)
		{
			break;
		}

		s++;
		i++;
	}

	return (i);
}
