
#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_string - prints a string
 * @str: string to print
 */
void print_string(char *str)
{
if (str == NULL)
str = "(nil)";
printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
va_list args;
unsigned int i = 0;
char *separator = "";

va_start(args, format);

while (format != NULL && format[i] != '\0')
{
switch (format[i])
{
case 'c':
printf("%s%c", separator, va_arg(args, int));
separator = ", ";
break;
case 'i':
printf("%s%d", separator, va_arg(args, int));
separator = ", ";
break;
case 'f':
printf("%s%f", separator, va_arg(args, double));
separator = ", ";
break;
case 's':
printf("%s", separator);
print_string(va_arg(args, char *));
separator = ", ";
break;
}
i++;
}

va_end(args);
printf("\n");
}
