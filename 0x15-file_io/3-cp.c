#include "main.h"
#include <stdio.h>
/**
 * print_errexit - print error message and exit
 * @str: error message as string
 * @file: file name as string
 * @code: exit code
 * Return: void
 */
void print_errexit(char *str, char *file, int code)
{
	dprintf(STDERR_FILENO, str, file);
	exit(code);
}

/**
 * _cp - copy source file to destination file
 * @file_from: source file
 * @file_to: destination file
 *
 * Return: void
 */
void _cp(char *file_from, char *file_to)
{
	int file1, file2, bytesread, byteswrote;
	char buffer[1024];

	file1 = open(file_from, O_RDONLY);
	if (file1 == -1)
		print_errexit("Error: Can't read from file %s\n", file_from, 98);

	file2 = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file2 == -1)
		print_errexit("Error: Can't write to %s\n", file_to, 99);

	bytesread = 1024;
	while (bytesread == 1024)
	{
		bytesread = read(file1, buffer, 1024);
		if (bytesread == -1)
			print_errexit("Error: Can't read from file %s\n", file_from, 98);

		byteswrote = write(file2, buffer, bytesread);

		if (byteswrote == -1)
			print_errexit("Error: Can't write to %s\n", file_to, 99);
	}

	if (bytesread == -1)
		print_errexit("Error: Can't read from file %s\n", file_from, 98);
	if (close(file2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d\n", file2);
		exit(100);
	}
	if (close(file1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d\n", file2);
		exit(100);
	}
}
/**
 *main - copies a file to another file
 *@argc: number of arguments passed to function
 *@argv: array containing arguments
 *Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	_cp(argv[1], argv[2]);

	return (0);
}
