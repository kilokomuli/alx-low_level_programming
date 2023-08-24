#include "main.h"

/**
 * rot13 - change letters to ROT13.
 * @s: analized string
 * Return: String with all letters in ROT13 base.
 */

char *rot13(char *s)
{
	char k[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i;
	int j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == k[j])
			{
				s[i] = rot[j];
				break;
			}
		}
	}
	return (s);

}
