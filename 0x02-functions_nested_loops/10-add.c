#include "main.h"
/r(',');
				_putchar(' ');
				
								prod = num * mult;
								
												if (prod <= 99)
						_putchar(' ');
										if (prod <= 9)
						_putchar(' ');
						
										if (prod >= 100)
					{
											_putchar((prod / 100) + '0');
																_putchar(((prod / 10)) % 10 + '0');
																				}
				else if (prod <= 99 && prod >= 10)
					{
											_putchar((prod / 10) + '0');
															}
				_putchar((prod % 10) + '0');
							}
			_putchar('\n');
					}
	}
}
**
 * add - Adds two integers.
 * @num1: The first integer to be added.
 * @num2: The second integer to be added.
 *
 * Return: The result of the addition.
 */
int add(int num1, int num2)
{
	return (num1 + num2);
 
