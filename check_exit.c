#include "shell.h"
/**
 *check_exit - check if the 1st user input was the exit string
 *@input: the tokenized input from the user
 *Return: nothing
 */
void check_exit(char **input)
{
	char *quit = "quit";

	if (*input == quit)
		exit(EXIT_SUCCESS);

	return;

}
