#include "main.h"
#include <stdio.h>
#include "2-strlen.c"

/**
 * rev_string - ecrire qtt en reverse
 - swap les pointer
 *@s: pointos
 * Return: Always 0.
 */

void rev_string(char *s)
{
char *start = s;
char *end = s + _strlen(s) - 1;

while (start < end)
{
	char tmp = *start;
	*start = *end;
	*end = tmp;
	start++;
	end--;
}
}
