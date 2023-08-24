#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int dlen = 0;
	int slen = 0;

	for (i = 0; dest[i] != '\0'; i++)
		dlen++;
	for (i = 0; src[i] != '\0'; i++)
		slen++;
	for (i = 0; i <= slen; i++)
		dest[dlen + i] = src[i];
	return (dest);
}
