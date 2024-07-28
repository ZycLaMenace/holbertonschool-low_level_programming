#include <stdio.h>

/**
 * main - count the number of arguments
 * @argc: number of arguments passed to the program
 * @argv: array of arguments passed to the program
 * Return: 0 if success
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
