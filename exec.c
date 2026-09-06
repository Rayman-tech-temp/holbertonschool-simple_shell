#include "main.h"

/**
 * find_env - replacement of getenv used in handling
 * PATH for commands.
 * @env: environment variables passed from Operating
 * System.
 * Return: char * - a pointer to the PATH env variable.
 */
char *find_env(char **env)
{
	unsigned int i;
	char *pattern, *key, *value, *temp;

	i = 0;
	pattern = "PATH";
	value = "banana";
	while (env[i] != NULL && strcmp(value, "banana") == 0)
	{
		temp = strdup(env[i]);
		key = strtok(temp, "=");
		if (strcmp(key, pattern) == 0)
			value = strtok(NULL, "=");

		i++;
		temp = NULL;
		free(temp);
	}
	if (temp != NULL)
		free(temp);

	return (value);
}
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
 * execprogram - execve example.
 * @command: the arguments/code being executed.
 * @env: passed env variable from main.
 * @path: prefix of command directory.
 * Return: Always 0.
 */
int execprogram(char **command, char **env)
{
	if (strcmp(*command, "env") == 0)
	{
		envprint(env);
		return (0);
	} else if (execve(command[0], command, env) == -1)
	{
		free(command);
		_exit(2);
	}
	return (0);
}

