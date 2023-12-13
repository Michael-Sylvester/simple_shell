#include "shell.h"

/**
 * builtin_cd - This is a builtin function
 * @args: The argument passed to the program
 */

int builtin_cd(char *args[])
{
	char *home = getenv("HOME");

	if (strcmp(args[0], "cd") != 0)
		return (1);
	if (args[1] == NULL)
	{
		strcpy(home, getenv("HOME"));
		if (home == NULL)
		{	perror("cd: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			perror("");
			return (1);
		}
		else 
			return (0);
	}
	else
	{
		if (chdir(args[1]) == 0)
			return (0);
		else
			perror(args[1]);
		return (1);
	}
}
