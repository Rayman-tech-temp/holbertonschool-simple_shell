#include "main.h"

/**
 * execprogram - execve example
 *
 * Return: Always 0.
 */
int execprogram(char **command)
{
	/**char *argv[] = {"/bin/ls", "-l", "/usr", NULL};*/
	
    if (execve(command[0], command, NULL) == -1)
    {
        perror("Error:");
    }
	execve(command[0], command, NULL);
    return (0);
}
