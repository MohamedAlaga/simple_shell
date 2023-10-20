#include "shell.h"
/**
 * execute - execute external program
 * @str: string to be executed
 * @argv: array of arguments
 * @env: array of environment variables
 * @av: array of arguments
 * Return: void
 */
void execute(char *str, char **argv, char **env, char **av)
{
int status, errno;
char *err = malloc(sizeof(char) * MAX_WIDTH);
pid_t childpid;
childpid = fork();
if (childpid < 0)
perror("\n");
else if (childpid == 0)
{
execve(str, argv, env);
strcat(err, av[0]);
perror(err);
free(str);
free(argv);
exit(1);
}
else
{
wait(&status);
check_interact();
}
}