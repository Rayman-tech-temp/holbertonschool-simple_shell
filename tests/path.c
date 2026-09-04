#include "main.h"

/**
 * find_path - finds the full path of a command
 * @command: command to find
 *
 * Return: full path or NULL
 */

char *find_path(char *command)
{
	char *path;
	char *dir;
	char *full_path;
	size_t length;

	if (command == NULL)
		return (NULL);

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));

		return (NULL);
	}

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path = strdup(path);
	if (path == NULL)
		return (NULL);

	dir = strtok(path, ":");

	while (dir != NULL)
	{
		length = strlen(dir) + strlen(command) + 2;

		full_path = malloc(length);
		if (full_path == NULL)
		{
			free(path);
			return (NULL);
		}

		printf(full_path, length, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
