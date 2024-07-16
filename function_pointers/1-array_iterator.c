#include "function_pointers.h"
#include <stdlib.h>

/**
 * array_iterator - action for each array
 * @array: array
 * @action: pointeur de fonction
 * @size: size of an array
 *
 * Return:
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}

}
