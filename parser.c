#include "shell.h"

/**
 * is_cmd - function that determines if a file is an executable command
 * @info: the information struct 
 * @path: path to the file
 *
 * Return: returns 1 if it is true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - function that duplicates characters
 * @pathstr: PATH string
 * @start: the starting index
 * @stop: the stopping index
 *
 * Return: pointer to the new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int j = 0, i = 0;

	for (i = 0, j = start; j < stop; j++)
		if (pathstr[j] != ':')
			buf[i++] = pathstr[j];
	buf[i] = 0;
	return (buf);
}

/**
 * find_path - function that finds this cmd in the PATH string
 * @info: info struct
 * @pathstr: PATH string
 * @cmd: cmd to find
 *
 * Return: the full path of cmd if it is found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int j = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[j] || pathstr[j] == ':')
		{
			path = dup_chars(pathstr, curr_pos, j);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}

