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

	/*if (non_int_shell(input, args, &size))
		return (0);
	*/
	while (start)
	{
		initialise_shell(&input, &size);
		getline(&input, &size, stdin);
		make_token(args, input);
		check_exit(input);

		command = args[0];
		if (command != NULL)/* function to fork and execute command*/
			execute(&command, args, &status);
		else
		{
			strcpy(command, args[0]);
			strcat(command, ": command not found\n");
			write(STDOUT_FILENO, command, sizeof(command));
		}
		free(command);
		free(input);
	}
		return (status);
}

/**
 *Non_int_shell - check if shell is being used non interactively
 *@input: the user input from stdin
 *@args:the list of arguments for the command
 *@size: size of the incoming command
 *Return: 0 for success and 1 error/failure
 */
/*
int non_int_shell(char **input, char *args[], size_t *size)
{
	pid_t child;
	char *command;

	command = args[0];
	if (strlen(command) > 0)
	{
		input = malloc(*size);
		if (input == NULL)
			exit(EXIT_FAILURE);

		getline(input, size, stdin);
		make_token(args, &input);
		command = args[0];

		if (find_path(&command))
		{
			execve(command, args, NULL);
			 This line runs only if execve fails 
			free(input);
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	free(input);
	return (0);
}
*/

/**
 *freedome- frees the memory used by input and read
 *@input: the user input
 *@oldcwd: the last workingdurectory
 *@read: value of getline
 *Return: nothing
 */
/*void freedome(char *input, char *oldcwd, int read)
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
*/
