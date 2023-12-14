#include "shell.h"

/**
 * builtin_cd - This is a builtin function
 * @args: The argument passed to the program
 */

int builtin_cd(char *args[], char **old)
{
	char *home = getenv("HOME");
	
	if (strcmp(args[0], "cd") != 0)
		return (1);
	if (args[1] == NULL)
	{
		if (home == NULL)
		{	
			perror("cd: HOME not set\n");
			return (1);
		}
		if (*old !=  NULL)
			free(*old);	
		*old = getcwd(NULL, 0);
		if (chdir(home) == 0)
			return (0);
	}
	else if (args[1] != NULL)
	{
		if (strcmp(args[1], "-") == 0)
		{	
			if (*old != NULL)
				chdir(*old);	
			else
				chdir(getcwd(NULL, 0));
			return (0);
		}
		else
		{
			if (*old != NULL)
				free(old);
			*old = getcwd(NULL, 0);
			chdir(args[1]);
			return (0);
		}
	}
	return (1);
}
