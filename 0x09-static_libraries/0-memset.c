#include "main.h"

/**
 * _memset -  fills memory with a constant byte.
 * @s: pointer to memory area to fill
 * @n: the number of bytes to fill
 * @b: constant byte
 * Return: a pointer to the memory area @s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		s[j] = b;
	return (s);
}
