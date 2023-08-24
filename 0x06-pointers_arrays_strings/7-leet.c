#include "main.h"

/**
 * leet - change vowels to numbers.
 * @s: analized string.
 *
 * Return: String with all vowels changed.
 */

char *leet(char *s)
{
	char c[] = "aeotlAEOTL";
	char d[] = "4307143071";
	int i = 0;
	int j;

	while (*(s + i) != '\0')
	{
		for (j = 0; j <= 9; j++)
		{
			if (*(s + i) == c[j])
			{
				*(s + i) = d[j];
			}
		}
		i++;
	}
	return (s);
}
