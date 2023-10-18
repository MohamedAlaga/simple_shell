#include "shell.h"

/**
 * main - the Main fucntion of shell
 */
extern int errno;
int main(int ac, char **av, char **env) {
  size_t buffer_size = MAX_SIZE;
  char *line = NULL, *str = malloc(sizeof(char) * MAX_WIDTH),
       *err = malloc(sizeof(char) * MAX_WIDTH), **argv;
  int status;
  pid_t childpid;

  (void)ac;
  check_interact();
  while (getline(&line, &buffer_size, stdin) != -1) {
    remove_newline(line);
    argv = tokenize(line);
    strcpy(str, "");
    if(check_env(argv[0], env))
    {
      ffree(argv);
      check_interact();
      continue;
    }
    if (!strcmp(argv[0], "exit")) 
    {
      ffree(argv);
      break;
    }
    strcat(str, argv[0]);
    childpid = fork();
    if (childpid < 0)
      perror("\n");
    else if (childpid == 0)
    {
      execve(str, argv, env);
      mult_strcat(err, av[0], ": 1:",argv[0]);
      perror(err);
      exit(1);
    }
    else
    {
      wait(&status);
      check_interact();
    }
    free(line);
    line = NULL;
    ffree(argv);
  }
  free(line);
  free(str);
  free(err);
  return (0);
}