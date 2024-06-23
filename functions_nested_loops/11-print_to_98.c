#include "main.h"

/**
 * print_to_98 - ecrire des nombres max 98
 *
 * Return: Always 0.
 */ 

void print_to_98(int n)
{
	int target = 98;

	if (n < target)
	{
		for (n <= target)
		{
			printf("%d\n", n);
				break;	
		}
		printf("%d, ", n);
			n++;
	}
	else if (n > target)
	{
		for (n >= target)
		{
			if (n == target)
			{
				printf("%d\n", n);
				break;
			}
			printf("%d, ", n);
			n--;
		}
	}
	else
	{
		printf("%d\n", n);
	}
}
