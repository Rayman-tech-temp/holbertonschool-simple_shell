#include "main.h"

/**
* read_line - reading the provided line
*
* Return: line without the '$'
*/

char *readline(void)
{
	char *buffer;
	size_t buffs;
	ssize_t reader;

	buffs = 0;
	printf("(_8^(|) ");
	reader = getline(&buffer, &buffs, stdin);
	if (reader == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (reader == 1)
	{
		free(buffer);
		return ("");
	}
	
		if (buffer[0] == '\n' || buffer[0] == '\0')
		{
			free(buffer);
			return ("");
		}

	printf("%s\n", buffer);
	return (buffer);
}
