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
char *path_finder(void);
int execprogram(char **command, char **env, int ac);
char **split_string(char *str);
char *find_path(char *command);
int envprint(char **env);
char *find_env(char **env)


#endif
