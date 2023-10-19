#include "shell.h"

/**
 * ffree - frees a string array
 * @str: string array to be freed
 *
 * Return: void
 */
void ffree(char **str)
{
int i = 0;
while (str[i] != NULL)
{
free(str[i]);
i++;
}
free(str);
}
/**
 * mult_strcat - concatenates multiple strings
 * @str: string to be created
 * @str1: string to be concatenated
 *
 * Return: void
 */
void mult_strcat(char *str, char *str1)
{
char *prefix = "/bin/";
if (strncmp(str1, "/bin/", 5) == 0 || strncmp(str1, "./", 2) == 0)
{
strcat(str, str1);
}
else
{
strcat(str, prefix);
strcat(str, str1);
strcpy(str1, str);
}
}
