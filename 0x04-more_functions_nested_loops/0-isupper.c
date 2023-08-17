#include "main.h"

/**
 *  _isupper - checks for uppercase character
 * @c: the character to be checked
 *  Return: 1 if c is uppercase
 *  or 0 if otherwise
 */

int _isupper(int c)
{
	for (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);

}
