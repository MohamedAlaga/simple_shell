#include "shell.h"

/**
 * ffree - frees a string array
 * @str: string array to be freed
 *
 * Return: void
 */
void ffree(char **str) {
  int i = 0;

  while (str[i] != NULL) {
    free(str[i]);
    i++;
  }
  free(str);
}

/**
 * mult_strcat - concatenates multiple strings
 * @str: string to be created
 * @str1: string to be concatenated
 * @str2: string to be concatenated
 * @str3: string to be concatenated
 *
 * Return: void
 */
void mult_strcat(char *str, char *str1)
{
  strcat(str, str1); 
}
