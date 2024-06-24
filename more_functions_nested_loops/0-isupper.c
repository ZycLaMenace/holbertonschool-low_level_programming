#include "main.h"
#include <stdio.h>

/**
 * main - isUpper savoir si c'est une maj.
 *
 * Return: Always 0 pour une miniscule.
 */

int _isupper(int c)

{
    if (c >= 'A' && c <= 'Z')
    return (1);
    else
    return (0);
}
