#include "main.h"
#include <stdio.h>
/**
 * print_array - ecrire les n elements a la suite
 * @a: pointeur vers le tableau d'entiers
 * @n: nombre d'éléments à imprimer
 * Return: Always 0.
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
<<<<<<< HEAD
    {
    	printf("%d", a[i]);
        if (i < n - 1)
    	{
            printf(", ");
        }
=======
	{
		printf("%d", a[i]);
		if (i < n - 1)
		{
			printf(", ");
		}
>>>>>>> b91971a1ab5f3163d18b1dda5a75e27874b13518
	}
	printf("\n");
}
