#include "main.h"

/**
 * print_diagonal - fais une diagonale
 *@n: variable
 * Return: Always 0.
 */

void print_diagonal(int n)

{
	int diaglen;

	for (diaglen = 0; diaglen < n; diaglen++)
	{
	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		_putchar('\\');
	}
	}
	_putchar('\n');
}
