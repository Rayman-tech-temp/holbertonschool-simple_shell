#include "main.h"

/**
 * execprogram - execve example
 * @command: the arguments/code being executed
 *
 * Return: Always 0.
 */
int execprogram(char **command)
{

	if (execve(command[0], command, environ) == -1)
	{
		perror("Error:");
		exit (-1);
	}
	return (0);
}
