#include "shell.h"
/**
 * check_env - checks for special commnads like environ and cd
 *@input: the user input
 *Return: 0 is successful and EXIT_FAILURE is fail
 */
int check_env(char *input)
{
	char **myenv;
	char *strenv = "env";

	if (strcmp(input, strenv) == 0)
	{
		for (myenv = environ; *myenv != NULL; myenv++)
		{
			printf("%s\n", *myenv);
		}
		return (0);
	}
	return (1);
}
