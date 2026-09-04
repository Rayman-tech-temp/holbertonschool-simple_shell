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

	status = 0;
	/**signal(SIGINT, SIG_IGN); */
	while (status == 0)
	{
		line = readline();
		if (strcmp(line, "") == 0)
		{
			perror("Error: no input");
			free(line);
		} else if (strcmp(line, "exit") == 0)
		{
			status = 1;
			printf("Goodbye!\n");
			_exit(1);
		} else if (strcmp(line, "") > 0)
		{
			av = split_string(line);
			child = fork();
		if (child == -1)
		{
			perror("Error:");
			exit(-1);
		}
		if (child == 0)
		{
			execprogram(av, env, ac);
		} else
		{
			wait(&status);
		}
		}
	}
		return (0);
}
