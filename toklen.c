#include "shell.h"
/**
 * toklen - gives the number of the tokens
 * @str: string to be tokenized
 *
 * Return: number of tokens
 */
int toklen(char *str)
{
char *token;
int toknum = 0;
token = strtok(str, " ");
while (token != NULL)
{
toknum++;
token = strtok(NULL, " ");
}
return (toknum);
}
