#include "main.h"

/**
 * print_square - fais un carre
 *@size: variable
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
