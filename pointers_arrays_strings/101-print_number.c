#include "main.h"

/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to be printed.
 */
void print_number(int n)
{
	int last_digit;

	if (n < 0)
	{
		_putchar(45);
		n = -n;
	}

	if (n == -2147483648)
	{
		_putchar('2');
		_putchar('1');
		_putchar('4');
		_putchar('7');
		_putchar('4');
		_putchar('8');
		_putchar('3');
		_putchar('6');
		_putchar('4');
		_putchar('8');
	}
	else
	{

		if (n < 10)
		{
			_putchar(n + '0');
			return;
		}

		last_digit = n % 10;

		print_number(n / 10);
		_putchar(last_digit + '0');
	}
}
