#include "main.h"
#include "2-strlen.c"

/**
 * puts_half - ecrire apres la moitié
 *@str: pointos
 * Return: Always 0.
 */

void puts_half(char *str)
{
int len = _strlen(str);
int moit = len / 2;
int txt;

if (len % 2 == 0)
{
	for (txt = moit; txt < len; txt++)
	{
		_putchar(str[txt]);
	}
}
else
{
	for (txt = moit + 1; txt < len; txt++)
	{
		_putchar(str[txt]);
	}
}
_putchar('\n');
}
