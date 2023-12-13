#include "shell.h"

/**
 *main - initializes variables for simple shell and
 *       calls all other functions of the shell
 *Return: 0 for success and 1 for faliure
 */
int main(void)
{
	int start = 1;
	size_t size = 1024;
	char *input = NULL,	 *command, *args[100];
	int status,	read;

	non_int_shell(&input, args, &size);
	while (start > 0)
	{
		initialise_shell(&input, &size);
		read = getline(&input, &size, stdin);
		make_token(args, input);
		if (check_exit(input) == 0 || read == EOF)
		{
			free(input);
			start = 0;
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (builtin_cd(args) == 0)
			free(input);
		else if (check_env(args[0]) == 0)
			free(input);
		else
		{
			command = args[0];
			if (find_path(&command) == EXIT_SUCCESS)
				execute(command, args, &status); /* function to fork and execute command*/
			else
			{
				strcpy(command, args[0]);
				strcat(command, ": command not found\n");
				write(STDOUT_FILENO, command, strlen(command));
			}
			free(command);
		}
	}
	return (0);
}

/**
 *non_int_shell - check if shell is being used non interactively
 *@input: the user input from stdin
 *@args:the list of arguments for the command
 *@size: the size of the buffer for allocating memory
 *Return: 1 for success and 0 for no command given
 */
void non_int_shell(char **input, char *args[], size_t *size)
{
	char *command;

	if (!isatty(fileno(stdin)))
	{
		*input = malloc(*size);
		if (*input == NULL)
			exit(EXIT_FAILURE);

		getline(input, size, stdin);
		make_token(args, *input);
		command = args[0];

		if (find_path(&command) == EXIT_SUCCESS)
		{
			execve(command, args, NULL);
			/* This line runs only if execve fails */
			free(*input);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			strcpy(command, args[0]);
			strcat(command, ": command not found\n");
			write(STDOUT_FILENO, command, strlen(command));
		}
		free(*input);
	}

}
/**
 *execute - executes commands that are viable
 *@command: the user input from stdin
 *@args:the list of arguments for the command
 *@status: hold the status information about the child process
 *Return: 0 for success and 1 error/failure
 */
int execute(char *command, char *args[], int *status)
{
	pid_t child;

	child = fork();
	if (child == 0)
	{
		if (execve(command, args, NULL) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (child > 0)
	{
		waitpid(child, status, 0);
		return (EXIT_SUCCESS);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
