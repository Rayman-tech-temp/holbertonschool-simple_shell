#include "main.h"

/**
 * execprogram - execve example
 * @command: the arguments/code being executed
 *
 * Return: Always 0.
 */
int execprogram(char **command)
{

	if (execve(command[0], command, NULL) == -1)
	{
		perror("Error:");
	}
	execve(command[0], command, NULL);
	return (0);
}
