#include "main.h"

/**
 * print_most_numbers - ecris les nombres
 * @i; variable
 * Return; les nombres sans 2 et 4
 */

void more_numbers(void)

{
	int i, a;
	
	for (i = 0; i <= 9; i++)
	{
		for (a = 0; a < 15; a++)
		{
			if (a > 9)
			{
				_putchar(a / 10 + '0');
			}
		_putchar(a % 10 + '0');
		}
		_putchar('\n');
	}
}
