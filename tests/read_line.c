#include "main.h"

/**
* readline - reading the provided line
*
* Return: line without the '$'
*/

char *readline(void)
{
	char *buffer;
	size_t buffs;
	int reader;

	buffs = 0;
	if (isatty(STDIN_FILENO))
	{
	printf("(ノಠ益ಠ)ノ彡 ");
	}
	reader = getline(&buffer, &buffs, stdin);
	if (reader != -1)
	{
		if (buffer[reader - 1] == '\n')
		{
			buffer[reader - 1] = '\0';
		}
		reader--;
	}
	else
	{
		buffer = "exit";
		return (buffer);
	}

	printf("%s\n", buffer);
	return (buffer);
}
