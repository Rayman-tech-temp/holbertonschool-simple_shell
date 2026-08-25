#include "main.h"
#include <stdio.h>

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
