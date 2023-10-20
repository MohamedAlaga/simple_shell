#include "shell.h"
/**
 * check_interact - checks if interactive
 *
 * Return: void
 */
void check_interact(void)
{
int interactive_mode = isatty(fileno(stdin));
if (interactive_mode)
printf("#cisfun$ ");
}
