#include "shell.h"
/**
 * tokenize - split input into array of words
 * @str: string to be tokenized
 *
 * Return: array of words
 */

char **tokenize(char *str)
{
char *token;
char *str_cpy = strdup(str);
char **words;
int len, i = 0;
char *buffer = str;
len = toklen(buffer);
words = malloc(sizeof(char *) * (len + 1));
if (words == NULL)
{
return (NULL);
}
token = strtok(str_cpy, " ");
while (token != NULL)
{
words[i] = strdup(token);
i++;
token = strtok(NULL, " ");
}
words[i] = NULL;
free(token);
free(str_cpy);
return (words);
}
