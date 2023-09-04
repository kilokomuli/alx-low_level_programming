#include "main.h"
#include <string.h>
#include <ctype.h>

/**
 * _strpbrk -  searches a string for any of a set of bytes
 * @s: the string to search
 * Return: a pointer to the byte in s  that matches one of the bytes in accept
 * or NULL if no such byte is found
 * @accept: second string
 */

char *_strpbrk(char *s, char *accept)
{
	int i, j;
	int len_s = strlen(s);
	int len_accept = strlen(accept);

	for (i = 0; i < len_s; i++)
	{
		for (j = 0; j < len_accept; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}
	return ('\0');
}
