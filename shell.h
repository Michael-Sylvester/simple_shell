#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;
/* Buffer */
/*Buffer needed here for holding user input. Size 1024*/
/* Functions */
char **split_string(char *input, char delim);
char **split_str_char(char *input, char *delim);
void make_token(char *args[], char *userinput);
void non_int_shell(char **input, char *args[], size_t *size);
int find_path(char **command);
void initialise_shell(char **input, size_t *size);
int check_exit(char *input);
int check_env(char *input);
int execute(char *command, char *args[], int *status);
int builtin_cd(char *args[]);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
ssize_t my_getline(char **lineptr, size_t *n, int fd);
int _putchar(char c);

#endif
