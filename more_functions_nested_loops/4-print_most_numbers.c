#include "main.h"

/**
 * print_numbers - ecris les nombres
 * @i; variable
 *
 */

void print_most_numbers(void)

{
	int i;
		for (i = '0'; i <= '9'; i++)
	{
        if (i == '2')
        	continue;
		if (i == '4')
			continue;
		_putchar(i);
	}
	_putchar('\n');
}
