#include "shell.h"

/**
 * bfree - function that frees a pointer and NULLs the address
 * @ptr: address of pointer to be freed
 *
 * Return: returns 1 when it is freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
