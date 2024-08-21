#include "shell.h"

/**
 * free_string - This function frees memory allocated for an array
 *of strings
 * @str_array: A pointer to an array of strings
 */
void free_string(char ***str_array)
{
	int x = 0;
	char **array;

	if (str_array == NULL || (*str_array) == NULL)
		return;

	array = *str_array;

	for (x = 0; array[x] != NULL; x++)
	{
		safefree(array[x]);
	}

	safefree(array);
	*str_array = NULL;
}

/**
 * _strncpy - This function copies up to n characters from the source string
 * to the destination.
 * @dest: The destination
 * @src: The source
 * @n: The number of characters to copy.
 * Return: A pointer to the destination
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int x = 0;

	while (x < n && src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}

	while (x < n)
	{
		dest[x] = '\0';
		x++;
	}

	return (dest);
}


/**
 * _isalpha - This function checks for alphabet.
 * @c: The parameter.
 * Return: Returns 1 if c is a letter, lowercase or uppercase.
 *
 */

int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}

	return (0);
}

/**
 * _strcmp - This function compares two strings.
 * @s1: The first string.
 * @s2: The 2nd string.
 * Return: 0 if @s1 and @s2 are equal, a negative value if @s1 is
 * less than @s2, a positive value if @s1 is greater than @s2.
 */

int _strcmp(char *s1, char *s2)
{
	int x = 0;

	while (s1[x] != '\0' && s2[x] != '\0')
	{
		if (s1[x] != s2[x])
		{
			return (s1[x] -  s2[x]);
		}
		x++;
	}

	return (0);
}
