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
	
	
	if (reader != -1)
	{
		if (buffer[reader - 1] == '\n')
		{
			buffer[reader - 1] = '\0';
		}
		reader--;
	}

	printf("%s\n", buffer);
	return (buffer);
}
