#include "main.h"

/**
 * check_prime - checks if n is prime
 * @n: number to check
 * @i: tester
 * Return: 1 if prime 0 if not prime
 */

int check_prime(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if n is prime
 * @n: number to check
 *
 * Return: 1 if prime 0 if not prime
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	return (check_prime(n, 2));
}
