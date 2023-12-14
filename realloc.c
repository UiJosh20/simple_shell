#include "shell.h"

/**
 * _memset - function that fills memory with a constant byte
 * @s: pointer to the memory area
 * @b: byte to fill *s with
 * @n: amount of bytes to be filled
 * Return: pointer to the memory address
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		s[j] = b;
	return (s);
}

/**
 * ffree - function that frees a string of strings
 * @pp: string of all strings
 */
void ffree(char **pp)
{
	char **b = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(b);
}

/**
 * _realloc - function that reallocates a block of memory
 * @ptr: the pointer to previous malloc'ated block
 * @old_size: the byte size of previous block
 * @new_size: the byte size of new block
 *
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *t;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	t = malloc(new_size);
	if (!t)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		t[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (t);
}

