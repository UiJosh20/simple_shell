#include "shell.h"

/**
 **_strncpy - function that copies a string
 *@dest: the destination string to be copied into
 *@src: the source string to be sourced
 *@n: the amount of characters to be copied
 *Return: the string to concatenate
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}

/**
 **_strncat - function that concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: the amount of bytes to be maximally used
 *Return: the string to concatenate
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *str = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (str);
}

/**
 **_strchr - function that locates a character in a string
 *@s: string to parse
 *@c: character to look for
 *Return: pointer to the memory address
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
