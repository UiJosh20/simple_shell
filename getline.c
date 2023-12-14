#include "shell.h"

/**
 * input_buf - function that buffers chained commands
 * @info: parameter struct input
 * @buf: address of the buffer
 * @len: address of length variable
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t t = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		t = getline(buf, &len_p, stdin);
#else
		t = _getline(info, buf, &len_p);
#endif
		if (t > 0)
		{
			if ((*buf)[t - 1] == '\n')
			{
				(*buf)[t - 1] = '\0'; 
				t--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = t;
				info->cmd_buf = buf;
			}
		}
	}
	return (t);
}

/**
 * get_input - function that gets a line minus the newline
 * @info: parameter struct of the function
 *
 * Return: bytes read into
 */
ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buffer, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buffer + i;

		check_chain(info, buffer, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buffer, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buffer;
	return (r);
}

/**
 * read_buf - function that reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: t
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t t = 0;

	if (*i)
		return (0);
	t = read(info->readfd, buf, READ_BUF_SIZE);
	if (t >= 0)
		*i = t;
	return (t);
}

/**
 * _getline - function that gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, t = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		t = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buffer, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buffer + i, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : len;
	new_p = _realloc(p, t, t ? t + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (t)
		_strncat(new_p, buffer + i, k - i);
	else
		_strncpy(new_p, buffer + i, k - i + 1);

	t += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = t;
	*ptr = p;
	return (t);
}

/**
 * sigintHandler - function that blocks using ctrl-C
 * @sig_num: signal num
 *
 * Return: void (nothing)
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

