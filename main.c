#include "shell.h"

/**
 *main - initializes variables for simple shell and
 *       calls all other functions of the shell
 *Return: 0 for success and 1 for faliure
 */
int main(void)
{
	int start = 1, status, read;
	size_t size = 0;
	char *input = NULL, *command, *args[100], *oldcwd = NULL;

	if (!isatty(fileno(stdin)))
		start = 2;
	while (start > 0)
	{
		if (start == 1)
			initialise_shell(&input, &size);
		read = getline(&input, &size, stdin);
		make_token(args, input);
		if (read == 1 || sizeof(args[0]) == 1)
		{
			free(input);
			continue;
		}
		if (check_exit(input) == 0 || read == EOF)
			freedome(input, oldcwd, read);
		if (builtin_cd(args, &oldcwd) == 0)
			free(input);
		else if (check_env(args[0]) == 0)
			free(input);
		else
			execute(&command, args, &status);

		if (start == 2)
			return (status);
	}
		return (status);
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
	pid_t child;
	
	*command = args[0];
	if (strlen(*command) > 0)
	{
		if (find_path(command) == EXIT_SUCCESS)
		{		/*execute(command, args, &status);*/
		

			child = fork();
			if (child == 0)
			{
				if (execve(*command, args, NULL) == -1)
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
			free(*command);
		}
		else
		{
			strcpy(*command, args[0]);
			strcat(*command, ": command not found\n");
			write(STDOUT_FILENO, command, strlen(*command));
		}
	}
	return (0);
}
/**
 *freedome- frees the memory used by input and read
 *@input: the user input
 *@oldcwd: the last workingdurectory
 *@read: value of getline
 *Return: nothing
 */
void freedome(char *input, char *oldcwd, int read)
{
	free(input);
	free(oldcwd);
	if (read == -1)
		puts("");
	exit(EXIT_SUCCESS);
}
