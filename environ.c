#include "shell.h"

/**
 * print_env - prints env
 * @env: enviroment
 *
 * Return: void
 */
void print_env(char **env) {
  int i = 0;
  while (env[i] != NULL) {
    printf("%s\n", env[i]);
    i++;
  }
}

/**
 * check_env - checks env
 * @arg: argument
 * 
 * Return: 1 if env, 0 of not
 */
int check_env(char *arg, char ** env) {
  if (!strcmp(arg, "env")) {
    print_env(env);
    return (1);
  }
  return (0);
}

/**
 * check_interact - checks if interactive
 *
 * Return: void
 */
void check_interact(void) {
  int interactive_mode = isatty(fileno(stdin));

  if (interactive_mode)
    printf("#cisfun$ ");
}