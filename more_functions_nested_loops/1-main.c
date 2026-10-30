
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

    r = _isdigit('0');
    printf("%d\n", r);

    r = _isdigit('5');
    printf("%d\n", r);

    r = _isdigit('9');
    printf("%d\n", r);

    r = _isdigit('a');
    printf("%d\n", r);

    r = _isdigit('!');
    printf("%d\n", r);

    return (0);
}
