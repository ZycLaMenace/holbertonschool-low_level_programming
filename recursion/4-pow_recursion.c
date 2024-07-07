#include "main.h"

/**
 * _pow_recursion - return result : number x power number y
 * @x: number
 * @y: number power
 * Return: value of x power y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	if (y == 1)
		return (x);

	return (x * _pow_recursion(x, y - 1));
}
