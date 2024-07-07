 #include "main.h"

/**
 * _strlen_recursion - calculating string lenght
 * @s: string
 *
 * Return: string lenght
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	return (1 + _strlen_recursion(s + 1));
}
