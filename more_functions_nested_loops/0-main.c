#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int r;

	r = _isupper('A');
	printf("%d\n", r);
	r = _isupper('a');
	printf("%d\n", r);
	r = _isupper('Z');
	printf("%d\n", r);
	r = _isupper(';');
	printf("%d\n", r);
	return (0);
}