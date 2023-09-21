#include <stdio.h>

void print_line(void) __attribute__ ((constructor));
/**
 * print_line -  prints a sentence before the main
 * function is excuted
 */

void print_line(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
