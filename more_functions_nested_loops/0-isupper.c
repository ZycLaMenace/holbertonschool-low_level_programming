#include "main.h"
#include <stdio.h>

/**
 * _isupper - isUpper savoir si c'est une maj.
 * @c: variable
 * Return: Always 0 pour une miniscule. et 1 pour MAJ
 */

int _isupper(int c)

{
	if (c >= 'A' && c <= 'Z')
	return (1);
	else
	return (0);
}
