#include "shell.h"
/**
 * _realloc - This function reallocates memory
 * @ptr:  The pointer to the memory block
 * @old_size: Size of old memory block
 * @new_size: Size of new memory block
 * Return: new pointer
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;
	size_t copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (ptr != NULL)
	{
		copy_size = (old_size < new_size) ? old_size : new_size;
		memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}
	return (new_ptr);
}
