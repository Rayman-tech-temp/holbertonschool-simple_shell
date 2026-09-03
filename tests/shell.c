#include "main.h"
/**
 * split_string - splitting string without white spaces
 * @str: the sring being split
 *
 * Return: split string
 */

char **split_string(char *str)
{
	char *token;
	char **array;
	size_t i;

	array = malloc(sizeof(str) * strlen(str));
	if (array == NULL)
	{
	return (NULL);
	}
	token = strtok(str, " ");
	i = 0;
	while (i < strlen(str) - 1)
	{
		array[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	array[i] = NULL;

	return (array);
}
/**
 * envvar - printing the enviorment
 * @ac: argument count
 * @av: the argument variables
 * @env: the enviorment
 *
 * Return: 0 Always
 */
int envvar(int ac, char **av, char **env)
{
	unsigned int i;
	char *pattern, *key, *value;

	i = 0;

	pattern = "_";
	while (env[i] != NULL)
	{
		key = strtok(env[i], "=");
		if (strcmp(key, pattern) == 0)
			value = strtok(NULL, "=");
		i++;
	}
	return (0);
}

/**
 * main - main shell
 *
 * Return: 0 Always
 */
int main(void)
{
	char *line, **args;
	int status;
	pid_t child;

	status = 0;
	signal(SIGINT, SIG_IGN);
	while (status == 0)
	{
		line = readline();
		if (strcmp(line, "") == 0)
		{
			perror("Error: no input");
			free(line);
		}
		else if (strcmp(line, "exit") == 0)
		{
			status = 1;
			printf("Goodbye!\n");
			_exit(1);
		}
		else if (strcmp(line, "") > 0)
		{
			args = split_string(line);
			child = fork();
		if (child == -1)
		{
			perror("Error:");
			exit(-1);
		}
		if (child == 0)
		{
			execprogram(args);
		}
		else
		{
			wait(&status);
		}
		}
	}
		return (0);
}
