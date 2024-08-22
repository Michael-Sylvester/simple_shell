#include "shell.h"

/**
 * _getenv - This function gets environment variable
 * @name: The variable name
 * Return: Pointer to the address of variable
 */
char *_getenv(const char *name)
{
	int len, flag, x, y;

	len = _strlen(name);

	for (x = 0; environ[x] != NULL; x++)
	{
		for (y = 0; y < len; y++)
		{
			if (name[y] == environ[x][y])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1 && environ[x][y] == '=')
			return (&environ[x][y + 1]);
		}
	return (NULL);
}
