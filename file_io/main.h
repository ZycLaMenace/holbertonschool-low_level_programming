#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

#define BUFFER_SIZE 1024

int close_file_free_buff(int file_descriptor, char *buf, int returnval);
	/** Function to shorten close file, free buff and return value */

int close_file_no_free(int file_descriptor, int returnval);
	/** Function to shorten close file without freeing buff and return value */

#endif /* MAIN_H */
