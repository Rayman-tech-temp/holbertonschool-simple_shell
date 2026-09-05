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
int execprogram(char **command, char **env, int ac, char *path);
void sighand(int sig);
char *path_finder(void);
char **split_string(char *str);
char *find_path(char *command, char **env);
char *path_search(char *path, char *command);
int envprint(char **env);
char *find_env(char **env);

#endif
