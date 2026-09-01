#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

int main(void)
{
	char *line;
	int status;
	pid_t child;
	pid_t my_pid;

	status = 0;
	my_pid = getpid();
	/*signal(SIGINT, SIG_IGN);*/
	while (status == 0)
	{
		line = readline();
		if (strcmp(line,"") == 0)
		{
			perror("Error: no input");
			free(line);
		}
		else if (strcmp(line,"exit") == 0)
		{
			status = 1;
			printf("Goodbye!\n");
			_exit(1);
		}
		else if(strcmp(line,"") > 0)
		{
			child = fork();
		  if (child == -1)
			{
				perror("Error:");
				exit (-1);
			}
		  if (child == 0)
			{
			
				printf("child %u\n", child);
				execprogram(line);
			}
			else
			{
				printf("my_pid %u\n", my_pid);
				wait(&status);
			}

		}
	}


		return (0);
	
}
