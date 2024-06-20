#include <stdio.h>

/**
 * main - Desc de la fonction
 * Return: Desc de la fonction
*/

int main(void)
{
char letter;
for (letter = 'a'; letter <= 'e' && letter <= 'q' && letter <= 'z'; letter++)
{
	putchar(letter);
}
putchar('\n');
	return (0);
}
