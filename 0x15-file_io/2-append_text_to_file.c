#include "main.h"
#include <string.h>
/**
 * append_text_to_file -  appends text at the end of a file.
 * @filename: name of the file
 * @text_content: is the NULL terminated string to
 * add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w;

	if (filename ==  NULL)
		return (-1);
	if (text_content == NULL)
		return (1);
	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);
	w = write(o, text_content, strlen(text_content));
	if (w == -1)
	{
		close(o);
		return (-1);
	}
	close(o);
	return (1);
}
