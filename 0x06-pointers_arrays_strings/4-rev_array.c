#include "main.h"

/**
 * reverse_array - prints reverse array.
 * @a: array to be compared.
 * @n: size of array.
 * Return: reversed array.
 */

void reverse_array(int *a, int n)
{
	int i;
	int j = 0;
	int k = n - 1;

	while (j < k)
	{
		i = *(a + j);
		*(a + j) = *(a + k);
		*(a + k) = i;
		j++;
		k--;
	}
}
