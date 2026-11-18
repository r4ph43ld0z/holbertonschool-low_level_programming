
#include <string.h>
#include "3-calc.h"

/**
 * get_op_func - selects the function corresponding to an operator
 * @s: operator given as argument
 * Return: pointer to the corresponding function, or NULL
 */
int (*get_op_func(char *s))(int, int)
{
op_t ops[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL}
};
int i = 0;

while (ops[i].op != NULL &&
(s == NULL || strcmp(s, ops[i].op) != 0))
i++;

return (ops[i].f);
}
