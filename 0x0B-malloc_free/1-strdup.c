#include "main.h"

/**
 * _strdup - Entry point
 * @str: string to duplicate
 * Return: a pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int n;
	int count = 0;
	char *cpy;

	if (str == NULL)
		return (NULL);
	for (n = 0; str[n] != '\0'; n++)
		count++;
	cpy = malloc(sizeof(char) * count + 1);
	if (cpy == NULL)
		return (NULL);
	for (n = 0; str[n] != '\0'; n++)
		cpy[n]  = str[n];
	return (cpy);
}
