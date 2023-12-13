#include "shell.h"

/**
 * builtin_cd - This is a builtin function
 * @args: The argument passed to the program
 */

void builtin_cd(char *args)
{
	if (args == NULL)
	{
		char *home = getenv("HOME");

	if (home == NULL)
	{
		perror("cd: HOME not set\n");
	}
	else
	{
	if (chdir(home) != 0)
	{
		perror("Directory couldn't change");
	}
	}
	}
	else
	{
	if (chdir(args) != 0)
	{
		perror("Directory couldn't change");
	}
	}
}
