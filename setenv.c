#include "shell.h"
/**
 * _setenv - Initialize a new environment variable,
 * or modify an existing one
 * @input: Array of strings, input user
 * @status: Checking for status
 * Return: 0 (success)
*/
ssize_t _setenv(char **input, ssize_t *status)
{
	char *p_value = NULL;
	char *p = NULL;
	ssize_t var_length, env_length;

	if (input[1] == NULL)
	{
		write(STDERR_FILENO, "usage: setenv VARIABLE VALUE", 28);
		*status = 2;
		return (0);
	}

	var_length =  _strlen(input[1]);
	p_value = _getenv(input[1]);

	for (env_length = 0; environ[env_length] != NULL; env_length++)
	{
	}
	p = malloc(sizeof(char) * (var_length + 1 + 1));
	free(p);
	p = NULL;

	if (p_value == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		p_value[0] = 'H';
		printf("%s\n", p_value);
	}
	return (0);
}
