#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Check if malloc work
 * @b: bytes
 * 
 * Return: res or 98 for failrue
*/

void *malloc_checked(unsigned int b)
{
	void *res;
	
	res = malloc(b);
	if (res == NULL)
		exit(98);
	return(res);
}
