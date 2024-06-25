#include <stdio.h>

/**
 * main - fais une diagonale
 *@n: variable
 * Return: Always 0.
 */

int main(void)
{
	int i;

	for (i = 0; i < 100; i++)
	{
		if (i / 3 == 0 && i / 5 == 0)
			printf("FizzBuzz");
		else if (i / 3 == 0)
			printf("Fizz");
		
		else if (i / 5 == 0)
			printf("Buzz");
		printf("%d ", i);
	}
	return (0);
}
