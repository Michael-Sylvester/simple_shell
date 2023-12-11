#include "shell.h"

/**
 * split_str_char - This function splits string
 * @input: The input
 * @delim: The delimeter string
 * Return: A pointer to an array of strings, otherwise NULL on failure
 */

char **split_str_char(char *input, char *delim)
{
	int my_input = 0, countWord = 0, len = 0, numWords = 0;
	int y;
	char **letters;

	if (input == NULL || input[0] == 0)
		return (NULL);

	if (!delim)
		delim = " ";

	while (input[my_input] != '\0')
	{
		if (!isDelim(input[my_input], delim) && (isDelim(input[my_input + 1], delim) || !input[my_input + 1]))
		{
			numWords++;
			my_input++;
		}
		if (numWords == 0)
			return (NULL);

		letters = malloc((1 + numWords) * sizeof(char *));
		if (!letters)
			return (NULL);
		for (my_input = 0, countWord = 0; countWord < numWords; countWord++)
		{
			while (isDelim(input[my_input], delim))
				my_input++;
			len = 0;
			while (!isDelim(input[my_input + len], delimiter) && input[my_input + len])
				len++;
			letters[countWord] = malloc((len + 1) * sizeof(char));
			if (!letters[countWord])
			{
				for (len = 0; len < countWord; len++)
					free(letters[len]);
				free(letters);
				return (NULL);
			}
			for (y = 0; y < len; y++)
				letters[countWord][y] = input[my_input++];
			letters[countWord][len] = 0;
		}
		letters[countWord] = (NULL);
		return (letters);
	}
}
/**
 * split_string - This splits strings into letters
 * @input: The input
 * @delim: The delim string
 * Return: A pointer to an array of strings, or NULL
 */
char **split_string(char *input, char delim)
{
	int _input = 0, countWord = 0, len = 0, numWords = 0;
	char **letters;
	int x;

	if (input == NULL || input[0] == 0)
		return (NULL);
	while (input[_input] != '\0')
	{
		if ((input[_input] != delim && input[_input + 1] == delim) ||
			(input[_input] != delim && !input[_input + 1]) || input[_input + 1] == delim)
			numWords++;
		_input++;
	}
	if (numWords == 0)
		return (NULL);
	letters = malloc((1 + numWords) * sizeof(char *));
	if (!letters)
		return (NULL);
	for (_input = 0, countWord = 0; countWord < numWords; countWord++)
	{
		while (input[_input] == delim && input[_input] != delim)
			_input++;
		len = 0;
		while (input[_input + len] != delim && input[_input + len] && input[_input + len] != delim)
			len++;
		letters[countWord] = malloc((len + 1) * sizeof(char));
		if (!letters[countWord])
		{
			for (len = 0; len < countWord; len++)
				free(letters[len]);
			free(letters);
			return (NULL);
		}
		for (x = 0; x < len; x++)
			letters[countWord][x] = input[_input++];
		letters[countWord][len] = 0;
	}
	letters[countWord] = NULL;
	return (letters);
}
