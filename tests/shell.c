#include "main.h"

/**
 * main - running the main shell
 *
 * Return: 0 always
 */
int main(void)
{
	char *line;
	int status = 0;
	pid_t child;

	/*signal(SIGINT, SIG_IGN);*/
	while ((line = readline()) != NULL);
	{
		if (strcmp(line, "") == 0)
		{
			perror("Error: no input");
			continue;
		}
		else if (strcmp(line, "exit") == 0)
		{
			printf("Goodbye!\n");
			free(line);
			_exit(1);
		}
		else if (strcmp(line, "") > 0)
		{
			child = fork();
			if (child == -1)
			{
				perror("Error:");
				exit(-1);
			}
			if (child == 0)
			{
				execprogram(line);
				free(line);
			}
			else
			{
				wait(&status);
			}
			free(line);
		}
	}
		return (0);

}
