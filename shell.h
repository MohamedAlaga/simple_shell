#ifndef SHELL_H
#define SHELL_H
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX_SIZE 1024
#define MAX_WIDTH 100
void check_interact(void);
void remove_newline(char *str);
char **tokenize(char *str);
int toklen(char *str);
void mult_strcat(char *str, char *str1);
void execute(char *str, char **argv, char **env, char **av);
#endif
