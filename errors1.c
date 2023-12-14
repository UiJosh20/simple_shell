#include "shell.h"

/**
 * _erratoi - function that converts a string to an integer
 * @s: the string to be converted
 * Return: 0 is returned if no num in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int j = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++; 
	for (j = 0;  s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			res *= 10;
			res += (s[j] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - function that prints an error message
 * @info: the params & return info struct
 * @estr: string that contains specified error type
 * Return: 0 is returned if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a dec (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to write into.
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, counter = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		counter++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_abs_ / j)
		{
			__putchar('0' + current / j);
			counter++;
		}
		current %= j;
	}
	__putchar('0' + current);
	counter++;

	return (counter);
}

/**
 * convert_number - function converter 
 * @num: num
 * @base: base number
 * @flags: argument to flags
 *
 * Return: a string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do	{
		*--p = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * remove_comments - function to replace first instance of '#' with '\0'
 * @buf: address of the string to be modified
 *
 * Return: Always return 0;
 */
void remove_comments(char *buf)
{
	int j;

	for (j = 0; buf[j] != '\0'; j++)
		if (buf[j] == '#' && (!j || buf[j - 1] == ' '))
		{
			buf[j] = '\0';
			break;
		}
}
