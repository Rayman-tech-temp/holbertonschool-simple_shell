#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

extern char **environ;

char *readline(void);
void sighand(int sig);
int execprogram(char **command);
char **split_string(char *str);
int envvar(int ac, char **av, char **env);


#endif
