#include "shell.h"

/**
 * _free - This frees a pointer and dynamically allocated memory
 * and sets it to NULL.
 * @p: A pointer to the pointer to be freed.
 */

void _free(void **p)
{
	if (p != NULL && *p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
