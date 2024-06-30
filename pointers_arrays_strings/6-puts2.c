#include "main.h"

/**
 * puts2 - ecrire txt en sautant chaque char par 2
 *@str: pointos
 * Return: Always 0.
 */

void puts2(char *str)
{
	int txt;

	int i;

	if (_strlen(str) == 0)
	{
		_putchar('\n');
	}

	for (txt = 0; str[txt] != '\0'; txt+=2)
	{
		_putchar(str[txt]);
	}
	_putchar('\n');
}
