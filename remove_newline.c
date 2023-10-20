#include "shell.h"
/**
 * remove_newline - removes newline from string and starting white space
 * @str: string to be cleaned
 *
 * Return: void
 */
void remove_newline(char *str) {
char *dst = str;
int len = strlen(str);
if (str[len - 1] == '\n') {
str[len - 1] = '\0';
}
while (*str == ' ') {
str++;
}
if (str != dst) {
while (*str) {
*dst++ = *str++;
}
*dst = '\0';
}
}