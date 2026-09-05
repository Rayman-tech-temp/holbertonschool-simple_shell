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
 * sighand - handling the SIGINT
 * @sig: the signal being used.
 */
void sighand(int sig)
{
	signal(sig, sighand);
	printf("\n(ノಠ益ಠ)ノ彡 ");
	fflush(stdout);
	
}

/**
 * envvar -
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
 * @ac: argument counter
 * @av: argument value
 * @env: enviorment variables
 *
 * Return: 0 Always
 */
int main(int ac, char **av, char **env)
{
	char *line;
	int status;
	pid_t child;
	
	ac = 0;
	status = 0;
	while (ac == 0)
	{
		signal(SIGINT, sighand);
		line = readline();
		if (strcmp(line, "") == 0)
		{
			perror("Error: no input");
			free(line);
		} else if (strcmp(line, "exit") == 0)
		{
			status = 1;
			printf("Goodbye!\n");
			_exit(status);
		} else if (strcmp(line, "") > 0)
		{
			av = split_string(line);
			child = fork();
		if (child == -1)
		{
			perror("Error");
			_exit(-1);
		}
		if (child == 0)
		{
			execprogram(av);
		} else
		{
			wait(&status);
		}
		}
		free(line);
	}
		return (status);
}
