#include "shell.h"

/**
 * find_path - This function searches for the cmd in the PATH
 * @command: The parameter declared
 * Return: All PATH of command  if found or NULL
 */

int find_path(char **command)
{
	char *path_copy = strdup( getenv("PATH"));
	char *all_path = malloc(1024);
	char *folder = strtok(path_copy, ":");

	if (access(*command, F_OK) == 0 && access(*command, X_OK) == 0)
		{/*check if the command is executable as is*/
			free(path_copy);
			free(all_path);
			return(EXIT_SUCCESS);
		}

	if(all_path == NULL)
	{
		free(path_copy);
		perror("malloc");
		return (EXIT_FAILURE);
	}
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
			*command = all_path;
			return (EXIT_SUCCESS);
		}
		folder = strtok(NULL, ":"); /* Proceed to the next folder */
	}
		free(path_copy);
		free(all_path);
		return (EXIT_FAILURE);
}
