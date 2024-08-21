#include "shell.h"

/**
 * _strchr - This function finds a character in a string
 * @str: The string
 * @c: The character to find
 * Return: pointer to @s
 */
char *_strchr(char *str, char c)
{
	if (str == NULL) /* checks if string is empty */
		return (NULL);

	while (*str != '\0')
	{
		if (*str == c)
		{
			return (str);
		}
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
