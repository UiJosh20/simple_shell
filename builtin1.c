#include "shell.h"

/**
 * _myhistory - display the current history list, one command per line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure that contains potential arguments.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - function that set alias to string
 * @info: parameter of  struct
 * @str: the string to that alias
 *
 * Return: Always 0 when successful, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *ptr, c;
	int r;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	c = *ptr;
	*ptr = 0;
	r = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ptr = c;
	return (r);
}

/**
 * set_alias - function that sets alias to string
 * @info: parameter of struct
 * @str: the string that alias
 *
 * Return: Always 0 when success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - function that prints an alias string
 * @node: the alias to a node
 *
 * Return: Always 0 when successful, 1 on error
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *b = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (b = node->str; b <= ptr; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - functions that mimics the alias builtin (man alias)
 * @info: Structure that contains potential arguments.
 *  Return: Always return 0
 */
int _myalias(info_t *info)
{
	int j = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; info->argv[j]; j++)
	{
		ptr = _strchr(info->argv[j], '=');
		if (ptr)
			set_alias(info, info->argv[j]);
		else
			print_alias(node_starts_with(info->alias, info->argv[j], '='));
	}

	return (0);
}
