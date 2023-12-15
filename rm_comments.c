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
	if (set == NULL || (set > cmd && isspace(*(set - 1))))
		return (cmd); /*NO comment */

	unset = set - cmd;
	modified_cmd = malloc(unset + 1);
	/* confirm if there is comment at the start of the string or follows whitespace */
	if (modified_cmd == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

		/* Copy the important part of  command into the new string */
		_strncpy(modified_cmd, cmd, unset);
		modified_cmd[unset] = '\0';
		return (modified_cmd);
}
