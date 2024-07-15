#include "function_pointers.h"
#include <stdlib.h>

/**
 * print_name - imprime le nom
 * @name: pointeur pour le nom
 * @f: pointeur de fonction avec parametre char *
 * 
 * Return:
*/

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
