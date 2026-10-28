#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers,
 * separated by ,, followed by a space, in ascending order.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
int j;
int k;

for (i = '0'; i <= '8'; i++)
{
for (j = i + 1; j <= '9'; j++)
{
putchar(i);
putchar(j);
if (i == '8' && j == '9')
{
k = '\n';
}
else
{
k = ',';
putchar(k);
k = ' ';
}
putchar(k);
}
}

return (0);
}
