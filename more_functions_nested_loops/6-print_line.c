#include "main.h"

/**
 * print_line - trace une ligne
 * @n; longuer de la ligne
 * Return; une ligne
 */

 void print_line(int n)
 {
	int linelen;

	for (linelen = 0; linelen < n; linelen++)
	{
	if (n <= 0)
		{
			_putchar('\n');
		}
	else
	{
		_putchar('_');
		
	}
	}
	_putchar('\n');
 }
 