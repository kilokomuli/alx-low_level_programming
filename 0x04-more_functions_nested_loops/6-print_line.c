#include "main.h"

/**
 *  print_line - draws a straight line
 *  @n: number of times the character _ should be printed
 *  return: 0
 */

void print_line(int n)
{
	int q = 0;

	if (n > 0)
	{
		while (q <= n)
		{
			_putchar('_');
			q++;
		}
		_putchar('\n');
	}
	else
	{
		_putchar('\n');
	}
}
