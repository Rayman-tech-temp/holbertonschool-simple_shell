#include <stdio.h>
#include <unistd.h>

/**
* main - finding the PID of the calling process
*
* Return: PPID, or 0 if fail.
*/
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
