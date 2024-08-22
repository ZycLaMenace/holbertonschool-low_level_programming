#include "main.h"

/**
 * swap_int - swap the value of two integers
 *@a: value to be swapped with b
 *@b: value to be swapped with a
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
