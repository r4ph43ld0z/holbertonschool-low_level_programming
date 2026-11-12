#include "main.h"
#include <stdlib.h>

/**
* _strdup - duplicates a string
* @str: string to duplicate
* Return: pointer to the duplicated string, or NULL
*/
char *_strdup(char *str)
{
char *copy;
unsigned int i;
unsigned int len;

if (str == NULL)
return (NULL);

len = 0;
while (str[len] != '\0')
len++;

copy = malloc(sizeof(char) * (len + 1));

if (copy == NULL)
return (NULL);

for (i = 0; i < len; i++)
copy[i] = str[i];

copy[i] = '\0';

return (copy);
}
