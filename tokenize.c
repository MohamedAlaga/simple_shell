#include "shell.h"

/**
 * toklen - gives the number of the tokens
 * @str: string to be tokenized
 *
 * Return: number of tokens
 */
int toklen(char *str) {
  char *token;
  int toknum = 0;

  token = strtok(str, " ");
  while (token != NULL) {
    toknum++;
    token = strtok(NULL, " ");
  }
  return (toknum);
}

/**
 * tokenize - split input into array of words
 * @str: string to be tokenized
 *
 * Return: array of words
 */

char **tokenize(char *str) {
  char *token;
  char *str_cpy = strdup(str);
  char **words;
  int len, i = 0;
  char *buffer = str;

  len = toklen(buffer);
  words = malloc(sizeof(char *) * (len));
  if (words == NULL) {
    return (NULL);
  }
  token = strtok(str_cpy, " ");
  while (token != NULL) {
    words[i] = strdup(token);
    i++;
    token = strtok(NULL, " ");
  }
  free(token);
  free(str_cpy);
  return (words);
}

/**
 * remove_newline - removes newline from string
 * @str: string to be cleaned
 *
 * Return: void
 */
void remove_newline(char *str) {
  int len = strlen(str);
  if (str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }
}
