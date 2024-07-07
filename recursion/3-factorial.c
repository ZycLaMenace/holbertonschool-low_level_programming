#include "main.h"

/**
 * factorial - factorial of n (n * (n- 1))
 * @n: number
 *
 * Return: factorial n or -1
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	if (n == 0)
	{
		return (1);
	}

return (n * factorial(n - 1));
}
