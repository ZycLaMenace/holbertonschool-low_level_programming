#include "main.h"

/**
 * _sqrt_helper - helps to guess the sqrt of n
 * @n: number that we want to find the square root
 * @guess: counter to help guess the sqrt
 * Return: sqrt of n
 */

int _sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - find the sqrt of n
 * @n: number to find the sqrt.
 * Return: sqrt of n
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}
