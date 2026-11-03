
#include "main.h"
#include <limits.h>

/**
* _atoi - converts a string to an integer
* @s: string to convert
* Return: converted integer
*/
int _atoi(char *s)
{
int sign = 1;
int result = 0;
int digit;
int limit;
int multmin;

while (*s && (*s < '0' || *s > '9'))
{
if (*s == '-')
sign = -sign;
s++;
}

limit = (sign == -1) ? INT_MIN : -INT_MAX;
multmin = limit / 10;

while (*s >= '0' && *s <= '9')
{
digit = *s - '0';

if (result < multmin)
return (sign == -1 ? INT_MIN : INT_MAX);

result *= 10;

if (result < limit + digit)
return (sign == -1 ? INT_MIN : INT_MAX);

result -= digit;
s++;
}

return (sign == -1) ? result : -result;
}
