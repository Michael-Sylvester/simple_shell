#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* Buffer */
/*Buffer needed here for holding user input. Size 1024*/

/* Functions */
void make_token(char *args[], char **userinput);
int non_int_shell(char *input, char *args[], size_t *size);
int find_path(char **command);
void initialise_shell(char **input, size_t *size);
void check_exit(char *input);
int execute(char *command, char *args[], int *status);
void builtin_cd(char *args);

#endif
