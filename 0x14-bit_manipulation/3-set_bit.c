#include "main.h"
#include <stdio.h>
/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: number of bytes
 * @index: The index to get the value at - indices start at 0.
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n ^= (1 << index);
	return (1);
}
