#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* Buffer */
//Buffer needed here for holding user input. Size 1024

/* Functions */
int make_token(char *args[], char *shellstr);
int non_int_shell(char *input, char*args[],size_t *size);
char *find_path(char *command);

#endif
