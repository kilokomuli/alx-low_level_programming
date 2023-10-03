#include "main.h"
#include <string.h>

/**
 * append_text_to_file -apeends text at the end of a file
 * @filename: is the name of the file
 * @text_content: is the NULL terminated string to add
 * at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, w;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL || text_content[0] == '\0')
		return (1);
	file = open(filename, O_WRONLY | O_APPEND);

	if (file == -1)
		return (-1);
	w = write(file, text_content, strlen(text_content));

	close(file);

	if (w == -1)
		return (-1);
	return (1);
}
