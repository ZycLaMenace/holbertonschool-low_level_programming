#include "main.h"
#include <stdio.h>

/**
 * swap_int - swap les pointer
 *@a: pointos 1
 *@b: pointos 2
 * Return: Always 0.
 */

void swap_int(int *a, int *b)
{
	int tmp;
	tmp = *a; *a = *b; *b = tmp;
}
