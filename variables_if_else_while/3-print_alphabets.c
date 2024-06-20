#include <stdio.h>

/**
 * main - Desc de la fonction
 * Return: Desc de la fonction
*/

int main(void)
{
char letter;
char Uletter;
for (letter = 'a'; letter <= 'z'; letter++)
{
	putchar(letter);
}
for (Uletter = 'A'; Uletter <= 'Z'; Uletter++)
{
	putchar(Uletter);
}
putchar('\n');
	return (0);
}
