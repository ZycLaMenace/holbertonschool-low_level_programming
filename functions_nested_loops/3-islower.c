#include "main.h"
/**
 * islower - savoir si c'est miniscule
 * @c: la variable
 * Return: Always 0 or 1 for lowercase
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	return (1);
	else
	return (0);
}
