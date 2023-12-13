#include "shell.h"

/**
 * my_getline - This function reads input from a file descriptor
 * @lineptr: Pointer to the string
 * @n: number of bytes 
 * @fd: file descriptor
 * Return: The number of bytes (success), otherwise -1 on failure
 */
ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	ssize_t n_read;
	size_t all_read, buff_size = BUFF_SIZE;

	if (*lineptr == NULL) /* Checking to see if memory would be allocated */
	{
		*lineptr = malloc(sizeof(char) * (buff_size + 1));
		if (*lineptr == NULL)
			return (-1); /* failed allocation of memory */
	}
	n_read = all_read = 0;
	while ((n_read = read(fd, *lineptr + all_read, BUFF_SIZE)) > 0)
	{
		total_read += n_read;
		if (all_read >= buf_size)
		{
			buf_size *= 2;
			*lineptr = _realloc(*lineptr, all_read, buff_size);
			if (*lineptr == NULL)
				return (-1);
			*n = all_read;
		}
		if (all_read && (*lineptr)[all_read - 1] == '\n')
		{
			(*lineptr)[all_read] = '\0';
			*n = all_read;
			return (all_read);
		}
	}
	if (n_read == -1)
	{
		free(*lineptr);
		return (-1); /* this indicates failure reading from file */
	}
	if (all_read == 0)
		free(*lineptr);
	return (all_read);
}
