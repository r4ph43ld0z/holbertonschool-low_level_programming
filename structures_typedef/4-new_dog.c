
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
char *dog_name;
char *dog_owner;

if (name == NULL || owner == NULL)
return (NULL);

dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);

dog_name = malloc(strlen(name) + 1);
if (dog_name == NULL)
{
free(dog);
return (NULL);
}

strcpy(dog_name, name);

dog_owner = malloc(strlen(owner) + 1);
if (dog_owner == NULL)
{
free(dog_name);
free(dog);
return (NULL);
}

strcpy(dog_owner, owner);

dog->name = dog_name;
dog->age = age;
dog->owner = dog_owner;

return (dog);
}
