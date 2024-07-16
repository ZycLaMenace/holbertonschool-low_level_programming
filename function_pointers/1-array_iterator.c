#include "function_pointers.h"
#include <stdlib.h>

/**
 * array_iterator - 
 * @array: array
 * @action: pointeur de fonction
 *
 * Return:
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
    int i;
    for (i = 0; array[i] < array[size]; i++)
    {
        action(array[i]);
    }
    
    return;
}
