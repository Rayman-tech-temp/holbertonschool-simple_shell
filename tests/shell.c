#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
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
	while (status == 0)
	{
		line = readline();
		if (strcmp(line, "") == 0)
		{
			perror("Error: no input");
			free(line);
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
