#include "shell.h"

/**
 * **strtow - func that splits a string into words.
 * @str: input string
 * @d: delimeter string
 * Return: pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int i, j, l, m, numword = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numword++;

	if (numword == 0)
		return (NULL);
	s = malloc((1 + numword) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numword; j++)
	{
		while (is_delim(str[i], d))
			i++;
		l = 0;
		while (!is_delim(str[i + l], d) && str[i + l])
			l++;
		s[j] = malloc((l + 1) * sizeof(char));
		if (!s[j])
		{
			for (l = 0; l < j; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - func that splits a string into words
 * @str: the input string
 * @d: delimeter
 * Return: pointer to array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, l, m, numword = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numword++;
	if (numword == 0)
		return (NULL);
	s = malloc((1 + numword) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numword; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		l = 0;
		while (str[i + l] != d && str[i + l] && str[i + l] != d)
			l++;
		s[j] = malloc((l + 1) * sizeof(char));
		if (!s[j])
		{
			for (l = 0; l < j; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < l; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

