#include "shell.h"
/**
 * main - the Main fucntion of shell
 * @ac: number of arguments
 * @av: arguments
 * @env: environment variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
size_t buffer_size = MAX_SIZE;
char *line = NULL, *str, *err = malloc(sizeof(char) * MAX_WIDTH), **argv;
int status, errno;
pid_t childpid;
(void)ac;
first:
check_interact();
while (getline(&line, &buffer_size, stdin) != -1)
{
str = malloc(sizeof(char) * MAX_WIDTH);
remove_newline(line);
if (strlen(line) == 0)
goto first;
argv = tokenize(line);
if (!strcmp(argv[0], "exit"))
{
free(argv);
free(str);
break;
}
mult_strcat(str, argv[0]);
execute(str, argv, env, av);
free(line);
line = NULL;
free(argv);
argv = NULL;
}
free(line);
free(err);
return (0);
}
