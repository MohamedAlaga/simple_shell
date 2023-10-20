#include "shell.h"
void check_interact(void)
{
int interactive_mode = isatty(fileno(stdin));
if (interactive_mode)
printf("#cisfun$ ");
}