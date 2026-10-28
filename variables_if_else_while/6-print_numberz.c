#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10 starting from 0,
 * followed by a new line, using only putchar twice and no char variables.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;

for (n = '0'; n <= '9'; n++)
{
putchar(n);
}
putchar('\n');

return (0);
}
