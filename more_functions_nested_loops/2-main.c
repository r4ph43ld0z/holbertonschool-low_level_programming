
#include "main.h"
#include <stdio.h>

/**
 * main - checks the code
 *
 * Return: Always 0
 */
int main(void)
{
    int r;

    r = mul(2, 3);
    printf("%d\n", r);

    r = mul(5, 5);
    printf("%d\n", r);

    r = mul(-4, 3);
    printf("%d\n", r);

    r = mul(0, 8);
    printf("%d\n", r);

    return (0);
}