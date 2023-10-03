#include "main.h"
#include <fcntl.h>

/**
 * read_textfile -  reads a text file and prints it to the
 * POSIX standard output
 * @filename: text file to read
 * @letters: number of letters it should read and print
 * Return:  actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, r, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	file = open(filename, O_RDONLY);
	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);
	if (file  == -1)
	{
		free(buffer);
		return (0);
	}
	r = read(file, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);
	close(file);
	return (w);
}
