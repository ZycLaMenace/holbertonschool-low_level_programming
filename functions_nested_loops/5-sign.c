#include "main.h"

/**
 * main - check the code.
 * @c: varible
 * Return: Always 0 or return zero or return 1
 */

int print_sign(int n)
{
int n;
	if (n = 0)
	{
		return (0);
	}
	if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('+');
		return (1);
	}
}
