#include "main.h"
#include <stddef.h>

/**
 * print_chessboard - print a chess board
 *@a: chessboard
 */

void print_chessboard(char (*a)[8])
{
	unsigned int i;
	unsigned int j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
	_putchar('\n');
	}
}
