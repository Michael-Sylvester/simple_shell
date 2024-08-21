#include "shell.h"
/**
 *check_exit - check if the 1st user input was the exit string
 *@input: the tokenized input from the user
 *Return: nothing
 */
<<<<<<< HEAD
int check_exit(char *input)
=======
void check_exit(char **input)
>>>>>>> parent of cba0db2... compleated shell. testing env function
{
	char *quit = "quit";

<<<<<<< HEAD
	if (strcmp(input, quit) == 0)
		return (0);
=======
	if (*input == quit)
		exit(EXIT_SUCCESS);
>>>>>>> parent of cba0db2... compleated shell. testing env function

	return;

}
