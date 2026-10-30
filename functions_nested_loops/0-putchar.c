#include <unistd.h>
#include "main.h" /* Suppose que main.h contient le prototype de _putchar */

/**
 * main - Point d'entrée du programme
 *
 * Description: Imprime "_putchar" suivi d'une nouvelle ligne
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
    char *str = "_putchar\n";
    
    while (*str)
    {
        _putchar(*str);
        str++;
    }
    return (0);
}
