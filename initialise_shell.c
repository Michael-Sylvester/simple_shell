#include "shell.h"

/**
 * initialise_shell - Allocate memory for the input string and display prompt
 * @input: string to hold user input
 * @size: size of the stringbuffer
 * Return: nothing
 */
void initialise_shell(char **input, size_t *size)
{
	if (*input != NULL)
		free(*input);

	*input = malloc(*size);
	if (*input == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	write(STDOUT_FILENO, "RMshell($)", 10);

}
