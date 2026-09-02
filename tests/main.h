#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>


char *readline(void);
int execprogram(char *command);
char **split_string(int size, char *str);


#endif
