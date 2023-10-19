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
int toklen(char *str);
char **tokenize(char *str);
void remove_newline(char *str);
void print_env(char **env);
int check_env(char *arg, char **env);
void ffree(char **str);
void check_interact(void);
void mult_strcat(char *str, char *str1);

#endif