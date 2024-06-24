#include "main.h"

/**
 * more_numbers - ecris les nombres jsq 14
 * @i; variable
 * Return; compte jusqu'a 14
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
