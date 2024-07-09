#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - 2D array of integers
 * @witdh: ligne
 * @height: colonne
 * Return: pointer to 2D array, NULL on failure
 */

int **alloc_grid(int width, int height)
{
	int i, j;
	int **grid;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = (int **)malloc(height * sizeof(int *));
		if (grid == NULL)
		{
			return (NULL);
		}

	for (i = 0; i < height; i++)
	{
	grid[i] = (int *)malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
			free(grid[j]);
			free(grid);
			return (NULL);
			}
		}
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}

	return (grid);
}
