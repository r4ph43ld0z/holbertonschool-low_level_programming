#include "main.h"

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 *
 * Return: Nothing.
 */
void rev_string(char *s)
{
int len;
int i;
char tmp;

len = 0;

while (s[len] != '\0')
len++;

len--;

for (i = 0; i < len; i++, len--)
{
tmp = s[i];
s[i] = s[len];
s[len] = tmp;
}
}
