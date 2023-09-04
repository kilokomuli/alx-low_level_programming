#include "main.h"

/**
 * _strcpy - copies string
 * @src: source
 * @dest: destination
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int j;

	for (j = 0; src[j] != '\0'; j++)
		dest[j] = src[j];
	dest[j] = '\0';
	return (dest);
}
