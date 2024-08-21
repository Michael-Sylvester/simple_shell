#include "shell.h"
/**
 *make_token - tokenisze input string
 *@args: an array to hold the list of arguments
 *@userinput: the string that the user typed
 *Return: nothing
 */
void make_token(char *args[], char *userinput)
{
	char *delimiter = " ";
	char *temp;
	int n = 0;

	remove_newline(&userinput);
	temp = strsep(&userinput, delimiter);

	while (temp != NULL)
	{
		while (*temp && *temp == ' ')
		{
			temp++;
		}
		if (temp == NULL)
			break;
		if (*temp && (*temp == '"' || *temp == '\''))
			quote_mode(&temp, args, n);
		else
		{
			temp = replace_comments(temp);
			args[n] = temp;
		}
		n++;
		temp = strsep(&userinput, delimiter);
	}
	args[n] = NULL;
}

/**
 *quote_mode- collect all information within quotes
 *@temp: address of pointer to token
 *@args: argument array
 *@n: array index
 *Return: nothing
 */
void quote_mode(char **temp, char *args[], int n)
{
	char quote = (*temp)[0];
	char *endquote;
	int j = 0;

	(*temp)++;
	while ((*temp) + j != NULL)
	{
		endquote = (*temp) + j;
		if (*endquote == quote)
			break;
		if (endquote == NULL)
		{
			perror("missing terminating quote");
			exit(-1);
		}
		j++;
	}
	*endquote = '\0';
	args[n] = *temp;
	*temp = endquote + 1;
}
/**
 *remove_newline- remove the newline chratcer at the end
 * at the end of user input due to pressing the enter key
 *@input: address of pointer to userinput
 *Return: nothing
 */
void remove_newline(char **input)
{
	if (strlen(*input) > 0 && *input != NULL)
	{
		if ((*input)[strlen(*input) - 1] == '\n')
			(*input)[strlen(*input) - 1] = '\0';
	}
}
