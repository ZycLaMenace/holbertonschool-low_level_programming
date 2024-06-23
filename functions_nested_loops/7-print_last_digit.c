#include "main.h"

/**
 * _int print_last_digit(int) - check the code
 * @ls: variable
 * Return: Always 0.
 */

int print_last_digit(int ls)
{
	ls = ls % 10;
	if (ls < 0)
	ls = -ls;    
	return(ls);
}
