#include "main.h"

/**
 * _memcpy - copies the memory area
 * @src: the memory are to copy from
 * @dest: where to copy the memory to
 * @n: bytes to be copied
 * Return: a pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		dest[j] = src[j];
	return (dest);
}
