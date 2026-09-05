#include "main.h"

/**
 * find_env - finds the PATH environment variable
 * @env: environment variables
 *
 * Return: pointer to PATH value, or NULL
 */
char *find_env(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}

	return (NULL);
}

/**
 * envprint - prints all environment variables
 * @env: environment variables
 *
 * Return: 0
 */
int envprint(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}

	return (0);
}

/**
 * execprogram - executes a command
 * @command: command and its arguments
 * @env: environment variables
 * @ac: argument count
 * @path: full path of the command
 *
 * Return: 0
 */
int execprogram(char **command, char **env, int ac, char *path)
{
	if (strcmp(command[0], "env") == 0)
	{
		envprint(env);
	}
	else if (execve(path, command, env) == -1)
	{
		printf("Error: %d:", ac);
		perror(" ");
	}

	return (0);
}
