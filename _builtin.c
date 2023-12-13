#include "shell.h"

/**
 * builtin_cd - This is a builtin function
 * @args: The argument passed to the program
 */

int builtin_cd(char *args[])
{
	char *home = getenv("HOME");
	char *cwd, *olddir;
	
	cwd = getcwd(NULL, 0);
	olddir = malloc(strlen(cwd));
	if (strcmp(args[0], "cd") != 0)
		return (1);
	if (args[1] == NULL)
	{
		if (home == NULL)
		{	perror("cd: HOME not set\n");
			return (1);
		}
		if (chdir(home) != 0)
		{
			perror("chdir");
			return (1);
		}
		else 
			return (0);
	}
	else if (args[1] != NULL)
	{
		if (strcmp(args[1], "-") == 0)
		{	
			write(STDOUT_FILENO, olddir, strlen(olddir));
		}
		else
		{
			strcpy(olddir, cwd);
			if(chdir(args[1]) == 0)
				cwd = getcwd(NULL, 0);
			return (0);
		}
	}
	return (1);
}

/*
char *cwd = home, *olddir;

	cwd = getcwd(cwd, 0);
	olddir = cwd;

if (strcmp(args[1], "-") == 0)
		{	
			write(STDOUT_FILENO, olddir, strlen(olddir));
		}
		else if (args[1] != NULL)
		{
			strcpy(olddir, cwd);
			if(chdir(args[1]) == 0)
				cwd = getcwd(cwd, 0);
			return (0);
		}*/