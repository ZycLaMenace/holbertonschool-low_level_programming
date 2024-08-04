#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout
 * @filename: Name of the file to read
 * @letters: Number of letters to read and print
 *
 * Return: Actual number of letters read and printed, or 0 if it fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread, nwritten;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	nread = read(fd, buffer, letters);
	if (nread == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	nwritten = write(STDOUT_FILENO, buffer, nread);

	free(buffer);
	close(fd);

	if (nwritten == -1 || nwritten != nread)
		return (0);

	return (nwritten);
}
