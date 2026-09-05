#include "main.h"

/**
 * find_env - replacement of getenv used in handling
 * PATH for commands.
 * @env: environment variables passed from Operating
 * System.
 * Returns: char * - a pointer to the PATH env variable.
 */
char *find_env(char **env)
{
    unsigned int i;
	char *pattern, *key, *value;
	
	i = 0;

	pattern = "PATH";
    while (env[i] != NULL)
    {
		key = strtok(env[i], "=");
		if (strcmp(key, pattern) == 0)
			value = strtok(NULL, "=");
        i++;
    }
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
 * @ac: argument count - use for error printing.
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
		printf("Error: %d:", ac);
		perror(" ");
	} else if (strcmp(*command, "env") != 0)
		execve(command[0], command, NULL);
	
	return (0);
}

