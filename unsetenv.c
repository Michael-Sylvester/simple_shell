#include "shell.h"
/**
 * _unsetenv - This eliminates  environmental variable
 * @input: Array of strings, input user
 * @status: Checking status
 * Return: 0 (success)
 */

ssize_t _unsetenv(char **input, ssize_t *status)
{
	if (input[1] == NULL)
	{
		write(STDERR_FILENO, "usage: unsetenv VARIABLE VALUE", 30);
		*status = 2;
		return (0);
	}
	return (0);
}
