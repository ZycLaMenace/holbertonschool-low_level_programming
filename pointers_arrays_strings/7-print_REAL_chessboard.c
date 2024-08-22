#include <stdio.h>

#define SIZE 8

/**
 * printChessboard - prints a REAL chessboard
 * @board: array to be printed
 */

void printChessboard(char board[SIZE][SIZE])
{
	printf("   a  b  c  d  e  f  g  h\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", 8 - i);
		for (int j = 0; j < SIZE; j++)
		{
			if ((i + j) % 2 == 0)
			{
				/* Light square */
				printf("\033[47m %c \033[0m", board[i][j]);
			}
			else
			{
				/* Dark square */
				printf("\033[40m %c \033[0m", board[i][j]);
			}
		}
		printf(" %d\n", 8 - i);
	}
	printf("   a  b  c  d  e  f  g  h\n");
}

/**
 * main - prints a chessboard
 * Return: 0 if success
 */
int main(void)
{
	char chessboard[SIZE][SIZE] = {
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
	};

	printChessboard(chessboard);
	return (0);
}
