#include "main.h"

/**
 * path_search - searches PATH for a command
 * @path: PATH environment variable
 * @command: command to find
 *
 * Return: full path or NULL
 */
char *path_search(char *path, char *command)
{
	char *dir;
	char *full_path;
	size_t length;

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		length = strlen(dir) + strlen(command) + 2;
		full_path = malloc(length);
		if (full_path == NULL)
			return (NULL);

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
			return (full_path);

		free(full_path);
		dir = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * find_path - finds the full path of a command
 * @command: command to find
 * @env: environment variables
 *
 * Return: full path or NULL
 */
char *find_path(char *command, char **env)
{
	char *path;
	char *result;

	if (command == NULL)
		return (NULL);

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));

	return (NULL);
	}

	path = find_env(env);
	if (path == NULL)
		return (NULL);

	path = strdup(path);
	if (path == NULL)
		return (NULL);

	result = path_search(path, command);
	free(path);

	return (result);
}
