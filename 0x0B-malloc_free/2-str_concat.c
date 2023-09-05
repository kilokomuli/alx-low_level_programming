#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer should point to a newly allocated space in memory or NULL
 */

char *str_concat(char *s1, char *s2)
{
	char *arr;
	int i;
	int s1len = 0;
	int s2len = 0;

	if (s1 == NULL)
		s1 = " ";
	if (s2 == NULL)
		s2 = " ";
	for (i = 0; s1[i] != '\0'; i++)
		s1len++;
	for (i = 0; s2[i] != '\0'; i++)
		s2len++;
	arr = malloc(sizeof(char) * (s1len + s2len) + 1);
	if (arr == NULL)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		arr[i] = s1[i];
	for (i = 0; s2[i] != '\0'; i++)
		arr[s1len + i] = s2[i];
	return (arr);
}
