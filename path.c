#include "shell.h"

/**
 * find_path - This function searches for the cmd in the PATH
 * @command: The parameter declared
 * Return: All PATH of command  if found or NULL
 */

char *find_path(char **command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);

	char all_path[1024];
	char *folder = strtok(path_copy, ":");

	while (folder != NULL) /* Looping through to iterate */
	{
		strcpy(all_path, folder);
		if (all_path[strlen(all_path) - 1] != '/')
		{
			strcat(all_path, "/");
		}
		strcat(all_path, *command);

	/* Checking for file if it exist and is executable */
		if (access(all_path, F_OK) == 0 && access(all_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(all_path));
		}
		folder = strtok(NULL, ":"); /* Proceed to the next folder */
	}
		free(path_copy);
		return (command);
}
