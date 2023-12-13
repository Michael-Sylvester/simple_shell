#include "shell.h"
/**
 *check_exit - check if the 1st user input was the exit string
 *@input: the tokenized input from the user
 *Return: nothing
 */
int check_exit(char **input)
{
	char *quit = "exit";

	if (**input == *quit)
		return(0);

	return (1);

}
