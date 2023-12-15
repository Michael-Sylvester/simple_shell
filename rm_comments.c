#include "shell.h"

/**
 * replace_comments -This function remove comments from a command
 * @cmd: The input command
 * Return: The modified cmd if # is found or cmd if # not found
 */
char *replace_comments(char *cmd)
{
	size_t unset;
	const char *set;
	char *modified_cmd;

	set = _strchr(cmd, '#');
	if (set == NULL)
		return (cmd);
	unset = set - cmd;

	/* confirm if there is comment at the start of the string or follows whitespace */
	if (unset == 0 || (unset > 0 && isspace(cmd[unset - 1])))
	{
		modified_cmd = malloc(unset + 1);
		if (modified_cmd == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			safefree(modified_cmd);
			exit(EXIT_FAILURE);
		}

		/* Copy the important part of  command into the new string */
		_strncpy(modified_cmd, cmd, unset);
		modified_cmd[unset] = '\0';
		return (modified_cmd);
	}
	else
	{
		return (cmd);
	}
}
