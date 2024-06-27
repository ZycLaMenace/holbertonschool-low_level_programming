#include "main.h"

/**
 * _puts - ecrire txt
 - swap les pointer
 *@str: pointos
 * Return: Always 0.
 */

void _puts(char *str)
{
	int txt;

	for (txt = 0; str[txt]; txt++)
	{
		_putchar(str[txt]);
	}
	_putchar('\n');
}
