#include "main.h"
#include <stdio.h>


char split_string(int size, char *str)
{
    char *token;
    char array[];
    int i;
    array = malloc(sizeof(str) * size);
    if (array == NULL || size == 0;)
    return (NULL);

    token = strtok(str, " ");
    i = 0
    while (i < size - 1)
    {
        array[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    array[i] = NULL;

    return array;
}


/**
 * execprogram - execve example
 *
 * Return: Always 0.
 */
int execprogram(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
