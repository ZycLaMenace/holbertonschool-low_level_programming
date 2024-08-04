
#include <fcntl.h>    /** For file control operations */
#include <unistd.h>   /** For POSIX constants and types */
#include <stdlib.h>   /** For memory management */
#include <stdio.h>    /** For standard I/O functions */
#include "main.h"


/**
 * main - Copies the content of one file to another.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, exits with different codes on errors.
 */

int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];
	char *pointer = buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], O_WRONLY | O_TRUNC, 0664);
	if (file_to <  0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(file_from);
		exit(99);
	}
	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
	while (bytes_read > 0)
	{
		bytes_written = write(file_to, pointer, bytes_read);
		if (bytes_written < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(file_from);
			close(file_to);
			exit(99);
		}
		bytes_read -= bytes_written;
		pointer += bytes_written;
	}
	if (bytes_read < 0)
	{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close(file_from);
			close(file_to);
			exit(99);
	}
	if (close(file_from) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		close(file_to);
		exit(100);
	}

	if (close(file_to) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
}
return (0);
}
