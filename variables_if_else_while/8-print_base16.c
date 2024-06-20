#include <stdio.h>

/**
 * main - Desc de la fonction
 * Return: Desc de la fonction
*/

int main(void)
{
char letter;
char num;

for (num = 0; num <= 9; num++)
{
	putchar(num);
}
for (letter = 'a'; letter <= 'f'; letter++)
{
	putchar(letter);
}
putchar('\n');
	return (0);
}
