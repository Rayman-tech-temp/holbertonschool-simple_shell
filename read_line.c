#include "main.h"


void trim(char *input)
{
	int i;
	int len;
	i = 0;
	len = strlen(input);
	i = len - 1;
	while (i >= 0 && input[i] == ' ')
	{
		input[i] = '\0';
		i--;
	}
	return;
}
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

	buffer = NULL;
	buffs = 0;
	if (isatty(STDIN_FILENO))
	{
	printf("(ノಠ益ಠ)ノ彡");
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
	
	if (reader == -1)
	{
		free(buffer);
		return ("exit");
	}
	trim(buffer);
	if (buffer[0] == '\0' || buffer[0] == '\n')
	{
		free(buffer);
		return ("");
	}
	return (buffer);
}
