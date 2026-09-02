#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

char *readline(void);
int execprogram(char *command);
char **split_string(int size, char *str);


#endif
