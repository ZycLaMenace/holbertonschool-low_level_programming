#include "main.h"

/**
 * print_last_digit - last digit
 * @ls: variable
 * Return: Always ls
 */

int print_last_digit(int ls)
{
	ls = ls % 10;
	if (ls < 0)
	ls = -ls;    
	return(ls);
}
