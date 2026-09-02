#include "main.h"

int main(void)
{
	char *line;
	int status;
	pid_t child;

	status = 0;
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
				execprogram(line);
			}
			else
			{
				wait(&status);
			}

		}
	}


		return (0);
	
}
