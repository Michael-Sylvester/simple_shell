#include "shell.h"
/**
 *make_token - tokenisze input string
 *@args: an array to hold the list of arguments
 *@userinput: the string that the user typed
 *Return: nothing
 */
void make_token(char *args[], char *userinput)
{
	char *delimiter = " \n";
	char *temp;
	int n = 0;

	temp = strtok(userinput, delimiter);

	while (temp != NULL)
	{
		args[n] = temp;
		n++;
		temp = strtok(NULL, delimiter);
	}
	args[n] = NULL;
}
