#include "main.h"

/**
 * print_rev - ecrire txt a l'envers
 *@s: pointos
 * Return: Always 0.
 */

void print_rev(char *s)
{
	int txt;

	for (txt = 0; s[txt]; txt++)
	{
	}
	txt--;
	while (txt >= 0)
	{
		_putchar(s[txt]);
		txt--;
	}
	_putchar('\n');
}
