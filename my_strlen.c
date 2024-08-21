#include "shell.h"

/**
 * _strlen - This returns the length of a string
 * @s: Pointer to the string
 * Return: length of string
*/
int _strlen(const char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
