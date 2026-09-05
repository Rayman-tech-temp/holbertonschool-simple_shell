#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

char *readline(void);
int execprogram(char **command, char **env, int ac);
char **split_string(char *str);
int envprint(char **env);
char *find_env(char **env)


#endif
