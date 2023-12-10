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
	char *input = NULL;
	char *command;
	char *args[100];
	int status;

	if (non_int_shell(input, args, &size))
		return (0);

	while (start)
	{
		initialise_shell(&input, &size);
		getline(&input, &size, stdin);
		make_token(args, &input);
		check_exit(&input);

		command = args[0];
		if (command != NULL)/* function to fork and execute command*/
			execute(command, args, &status);
		else
		{
			strcpy(command, args[0]);
			strcat(command, ": command not found\n");
			write(STDOUT_FILENO, command, sizeof(command));
		}
		free(command);
		free(input);
	}
	return (0);
}

/**
 *Non_int_shell - check if shell is being used non interactively
 *@input: the user input from stdin
 *@args:the list of arguments for the command
 *@size: the size of the buffer for allocating memory
 *Return: 1 for success and 0 for no command given
 */
int Non_int_shell(char *input, char *args[], size_t *size)
{
	char *command;

	if (!isatty(fileno(stdin)))
	{
		input = malloc(*size);
		if (input == NULL)
			exit(EXIT_FAILURE);

		getline(&input, size, stdin);
		make_token(args, &input);
		command = args[0];

		if (find_path(&command))
		{
			execve(command, args, NULL);
			/* This line runs only if execve fails */
			free(input);
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	free(input);
	return (0);
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
			perror("exceve");
		exit(EXIT_FAILURE);
	}
	else if (child > 0)
	{
		waitpid(child, status, 0);
		return (0);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
