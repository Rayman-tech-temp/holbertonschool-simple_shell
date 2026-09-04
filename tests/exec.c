#include "main.h"
/**
 * envprint - prints all env elements passed from
 * the Operating System to this function.
 * @env: passed main variable to this function.
 * Return: int - a number regarding success or
 * failure of execution of this function.
 */
int envprint(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i = i + 1;
	}
	return (0);
}

/**
 * execprogram - execve example
 * @command: the arguments/code being executed
 * @env: passed env variable from main
 * Return: Always 0.
 */
int execprogram(char **command, char **env, int ac)
{
	if (strcmp(*command, "env") == 0)
	{
		envprint(env);
	} else if (execve(command[0], command, NULL) == -1 
	&& strcmp(*command, "env") != 0)
	{
		perror("Error:");
		printf(" %d", ac);
	} else if (strcmp(*command, "env") != 0)
		execve(command[0], command, NULL);

	return (0);
}

