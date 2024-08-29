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
	int status = -100;
	int interactive = isatty(STDIN_FILENO); /*Check if running interactively*/

	while (start)
	{
		initialise_shell(&input, &size, interactive);
		status = getline(&input, &size, stdin);
		if (status == -1)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 2);
			free(input);
			exit(EXIT_SUCCESS);
		}

		make_token(args, input);
		if (keyword_checks(input) == 1)
		{
			freedome(input, NULL);
			continue;
		}

		command = args[0];
		if (command != NULL)/* function to fork and execute command*/
			execute(&command, args, &status);
		else
		{
			strcpy(command, args[0]);
			strcat(command, ": No such file or directory\n");
			write(STDOUT_FILENO, command, sizeof(command));
		}
		freedome(input, NULL);
	}
		return (status);
}

/**
 *non_int_shell - check if shell is being used non interactively
 *@input: the user input from stdin
 *@args:the list of arguments for the command
 *@size: size of the incoming command
 *Return: 0 for success and 1 error/failure
 */

int non_int_shell(char *input, char *args[], size_t *size)
{
	/*pid_t child;*/
	char *command;

	command = args[0];
	if (strlen(command) > 0)
	{
		input = malloc(*size);
		if (input == NULL)
			exit(EXIT_FAILURE);

		getline(&input, size, stdin);
		make_token(args, input);
		command = args[0];

		if (find_path(&command))
		{
			execve(command, args, NULL);
			/*This line runs only if execve fails*/
			freedome(input, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	freedome(input, NULL);
	return (0);
}


/**
 *freedome- frees the memory used by input and read
 *@input: the user input
 *@oldcwd: the last workingdurectory
 *Return: nothing
 */
void freedome(char *input, char *oldcwd)
{
	if (input != NULL && sizeof(*input) > 0)
		free(input);

	if (oldcwd != NULL)
		free(oldcwd);
}



/**
 *execute - executes commands that are viable
 *@command: the user input from stdin
 *@args:the list of arguments for the command
 *@status: hold the status information about the child process
 *Return: 0 for success and 1 error/failure
 */
int execute(char **command, char *args[], int *status)
{
	char *err;
	pid_t child;
	*command = args[0];


	if (strlen(*command) > 0)
	{
		if (find_path(command) == EXIT_SUCCESS)
		{		/*execute(command, args, &status);*/

			child = fork();
			if (child == 0)
			{
				if (execve(*command, args, environ) == -1)
					perror("execve");
				exit(EXIT_FAILURE);
			}
			else if (child > 0)
			{
				waitpid(child, status, 0);
			}
			else
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			/*free(*command);*/
			command = NULL;
		}
		else
		{
			err = malloc(strlen(args[0]) + strlen(": No such file or directory\n") + 1);
			strcpy(err, args[0]);
			strcat(err, ": No such file or directory\n");
			write(STDOUT_FILENO, err, strlen(err));
			free(err);
		}
	}
	return (0);
}
