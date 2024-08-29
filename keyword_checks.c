#include "shell.h"
/**
 *keyword_checks - tokenisze input string
 *@userinput: the string that the user typed
 *Return: nothing
 */
int keyword_checks(char *userinput)
{
	check_exit(userinput);
	if(check_env(userinput) == 0)
		return 1;
	return 0;
}