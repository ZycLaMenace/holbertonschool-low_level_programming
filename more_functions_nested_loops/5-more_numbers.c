#include "main.h"

/**
 * print_most_numbers - ecris les nombres
 * @i; variable
 * Return; les nombres sans 2 et 4
 */

void more_numbers(void)

{
	int i;
		for (i = '0'; i <= '9'; i++)
	{
		_putchar(i);
	}
	for (i = '0'; i <= '4'; i++)
	{
		int in = i % 10;
		_putchar('1' + in);
	}
	_putchar('\n');
}
