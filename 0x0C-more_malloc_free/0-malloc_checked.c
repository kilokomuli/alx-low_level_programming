#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of the memory to be allocated
 * Return: pointer to the address of the memory
 */
void *malloc_checked(unsigned int b)
{
	char *output;

	output = malloc(b);
	if (output == NULL)
		exit(98);
	return (output);
}
