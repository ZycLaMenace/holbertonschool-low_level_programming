#include "main.h"

/**
 * print_diagonal - fais une diagonale
 *@n: variable
 * Return: Always 0.
 */

void print_square(int size)

{
    int side;
    int carre;

    if (size <= 0)
	{
		_putchar('\n');
	}
    for (carre = 0; carre < size ; carre++)
    {
        for (side = 0; side < size; side++)
            {
		    _putchar('#');
        }
    _putchar('\n');
    }
}
