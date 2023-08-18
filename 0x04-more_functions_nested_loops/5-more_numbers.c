#include "main.h"

/**
 * more_numbers - prints 10 times the numbers
 * from 0 to 14
 * followed by a new line
 */

void more_numbers(void)
{
	int e;
	int k;

	for (e = 0; e < 10; e++)
	{
		for (k = 0; k <= 14; k++)
		{
			if (k > 9)
			{
				_putchar(k / 10 + '0');
			}
			_putchar(k % 10 + '0');
		}
		_putchar('\n');
	}
}
