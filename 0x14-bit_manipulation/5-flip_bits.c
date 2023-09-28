#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned int x;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		x = exclusive >> i;

		if (x & 1)
			count++;
	}
	return (count);
}
