#include "shell.h"

/**
 * interactive - true is returned if shell is in the interactive mode
 * @info: struct information address
 *
 * Return: interactive mode returns 1, 0 if not
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function to check if character is a delimeter
 * @d: the char to check
 * @del: the delimeter string
 * Return: 1 if it is true, 0 if false
 */
int is_delim(char d, char *del)
{
	while (*del)
		if (*del++ == d)
			return (1);
	return (0);
}

/**
 * _isalpha - functio to check for alphabetic character
 * @d: The character to input
 * Return: 1 if it is c is alphabetic, 0 otherwise
 */

int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - function to converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if it is no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int j, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (j = 0; str[j] != '\0' && flag != 2; j++)
	{
		if (str[j] == '-')
			sign *= -1;

		if (str[j] >= '0' && str[j] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (str[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}

