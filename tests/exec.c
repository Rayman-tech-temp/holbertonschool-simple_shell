#include "main.h"


char *path_finder (void)
{
	int i;
	char *env;
	char *path;
	char *token;

	i = 0;
	path = NULL;

	while (environ[i] != NULL)
	{
		env = malloc(sizeof(char) * (strlen(environ[i]) + 1));
		strcpy(env, environ[i]);
		token = strtok(env, "=");
		if (strcmp(environ[i], "PATH") == 0)
		{
			token = strtok(NULL, "=");
			if (token == NULL)
			{
				free(env);
				return (NULL);
			}
			path = malloc(sizeof(char) * (strlen(token) + 1));
			if (path == NULL || token == NULL)
			{
				free(env);
				return (NULL);
			}
			strcpy(path, token);
			free(env);
			break;
		}
		i = i + 1;
		free(env);
	}

	return (path);
}
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
