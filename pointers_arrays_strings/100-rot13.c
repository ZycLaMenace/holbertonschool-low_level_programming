#include "main.h"

/**
 * rot13 - converts a string switching to 13 pos on ascii table
 * @str: string to be converted
 *
 * Return: a pointer to the new string
 */
char *rot13(char *str)
{
	int a = 0;

	while (str[a])
	{
		while ((str[a] >= 'a' && str[a] <= 'z') || (str[a] >= 'A' && str[a] <= 'Z'))
		{
			if ((str[a] > 'm' && str[a] <= 'z') || (str[a] > 'M' && str[a] <= 'Z'))
			{
				str[a] -= 13;
				break;
			}

			str[a] += 13;
			break;
		}

		a++;
	}

	return (str);
}
