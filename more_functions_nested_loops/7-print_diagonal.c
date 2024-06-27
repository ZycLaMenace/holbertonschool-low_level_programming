#include "main.h"

/**
 * print_diagonal - fais une diagonale
 *@n: variable
 * Return: Always 0.
 */

void print_diagonal(int n)

{
	int diaglen;
	int alignement;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (diaglen = 0; diaglen < n; diaglen++)
		{
		for (alignement = 0; alignement < diaglen; alignement++)
		{
			_putchar(' ');
		}
	_putchar('\\');
	_putchar('\n');
	}
	}
}
