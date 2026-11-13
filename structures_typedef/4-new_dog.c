
#include <stdlib.h>
#include "dog.h"

/**
 * copy_string - copies a string
 * @str: string to copy
 * Return: pointer to copy or NULL
 */
char *copy_string(char *str)
{
char *copy;
int i;

for (i = 0; str[i]; i++)
;
copy = malloc(i + 1);
if (copy == NULL)
return (NULL);
for (i = 0; str[i]; i++)
copy[i] = str[i];
copy[i] = '\0';
return (copy);
}

/**
 * free_dog - frees a dog structure
 * @dog: dog to free
 */
void free_dog(dog_t *dog)
{
free(dog->name);
free(dog->owner);
free(dog);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * Return: pointer to new dog or NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;

if (name == NULL || owner == NULL)
return (NULL);
dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);
dog->name = copy_string(name);
if (dog->name == NULL)
{
free(dog);
return (NULL);
}
dog->owner = copy_string(owner);
if (dog->owner == NULL)
{
free_dog(dog);
return (NULL);
}
dog->age = age;
return (dog);
}
