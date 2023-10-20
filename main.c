#include "shell.h"
/**
 * errno - general variable for errors
 */
int errno;
/**
 * main - the Main fucntion of shell
 */
int main(int ac, char **av, char **env) {
  size_t buffer_size = MAX_SIZE;
  char *line = NULL, *str,*err = malloc(sizeof(char) * MAX_WIDTH), **argv;
  int status;
  pid_t childpid;
  (void)ac;
  first:
  check_interact();
  while (getline(&line, &buffer_size, stdin) != -1){
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
    free(line);
    line = NULL;
    free(argv);
    argv = NULL;
  }
  free(line);
  free(err);
  return 0;
}