#include "main.h"

/**
 * split_string - splits a string using spaces
 * @str: the string being split
 *
 * Return: array of strings
 */
char **split_string(char *str)
{
	char *token;
	char **array;
	size_t i;

	array = malloc(sizeof(char *) * (strlen(str) + 1));
	if (array == NULL)
		return (NULL);

	token = strtok(str, " ");
	i = 0;

	while (token != NULL)
	{
		array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	array[i] = NULL;

	return (array);
}


/**
 * run_command - finds and executes a command
 * @command: command and arguments
 * @env: environment variables
 * @ac: argument count
 *
 * Return: 0
 */
int run_command(char **command, char **env, int ac)
{
	char *path;
	pid_t child;
	int wait_status;

	path = find_path(command[0], env);
	if (path == NULL)
	{
		printf("Error: %d:", ac);
		perror(" ");
		return (0);
	}

	child = fork();
	if (child == -1)
	{
		perror("Error");
		free(path);
		return (0);
	}

	if (child == 0)
	{
		execprogram(command, env, ac, path);
		_exit(127);
	}

	wait(&wait_status);
	free(path);

	return (0);
}


/**
 * main - main shell
 * @ac: argument counter
 * @av: argument value
 * @env: environment variables
 *
 * Return: 0 Always
 */
int main(int ac, char **av, char **env)
{
        char *line;
        char **command;

        (void)av;

        while (1)
        {
                line = readline();
                if (line == NULL)
                        break;

                if (strcmp(line, "") == 0)
                {
                        free(line);
                        continue;
                }

                if (strcmp(line, "exit") == 0)
                {
                        free(line);
                        printf("Goodbye!\n");
                        break;
                }

                command = split_string(line);
                if (command == NULL)
                {
                        free(line);
                        continue;
                }

                run_command(command, env, ac);

                free(command);
                free(line);
	}

	return (0);
}
