#include "main.h"

/**
 * file_length - open and read a file and return the
 * file size to allow memory allocation.
 * @command: the typed command to look for
 * Return: size_t - the character length of a file.
 */
int file_length(char *command)
{
	int fd;
	size_t length;

	fd = 0;
	length = 0;

	return (length);
}

/**
 * print_manual - a function that finds the manual file the
 * user requests. the original can chain multiple prints
 * which IS NOT implemented
 * @:
 * Returns: int - returns 0 on success negative on type of failure.
 */

int print_manual(char *command, ...)
{
	char *buffer;
	int state, fd;
	size_t characters;

	state = 0;
	fd = 0;
	chracters = file_length(command);

	buffer = malloc(sizeof(char) * [file size])
	if (buffer == NULL)
	{
		state = -4;
		return (state);
	} else if (commnd != NULL)
	{
		fd = open(command, O_RDONLY);
		if (fd == -1)
		{
		state = -1;
		return (state);
		}

		[file size] = read(fd, buffer, [file size]);
		write(1, buffer, [file size]);
		close(fd);
	}

	return (state);
}
