#include "main.h"
#include <stdio.h>

/**
 * _isdigit - isUpper savoir si c'est une maj.
 * @c: variable
 * Return: Always 0 pour une miniscule. et 1 pour MAJ
 */

int _isdigit(int c)

{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
