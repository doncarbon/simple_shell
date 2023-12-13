#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

char *prompt();
char **split(char *input);
int executor(char **command, char **argv, int index);
void free2d(char **array);
char *_getenv(char *str);
char *pathfinder(char *cmd);
void error(char *shell, char *cmd, int index);
void print_environment(void);
int builtin_exit(char **command);

#endif
