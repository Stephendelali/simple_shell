#include "shell.h"

/**
 * _myhistory - shows the history list command by command, with line numbers
 *              from 0.
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias - sets strings
 * @inf: parameter
 * @str: the string alias
 *
 * Return: feturns 9 or 1 for error
 */
int unset_alias(info_t *inf , char *str)
{
	char *l, k;
	int ret;

	l = _strchr(str, '=');
	if (!l)
		return (1);
	k = *l;
	*l = 0;
	ret = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, str, -1)));
	*l = k;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @inf: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *inf, char *str)
{
	char *l;

	l = _strchr(str, '=');
	if (!l)
		return (1);
	if (!*++l)
		return (unset_alias(inf, str));

	unset_alias(inf, str);
	return (add_node_end(&(inf->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *l = NULL, *a = NULL;

	if (node)
	{
		l = _strchr(node->str, '=');
		for (a = node->str; a <= l; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(l + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @inf: Structure that might support arguments. utilized to preserve the
 *         prototype of the constant function.
 *  Return: Always 0
 */
int _myalias(info_t *inf)
{
	int i = 0;
	char *l = NULL;
	list_t *node = NULL;

	if (inf->argc == 1)
	{
		node = inf->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; inf->argv[i]; i++)
	{
		l = _strchr(inf->argv[i], '=');
		if (l)
			set_alias(inf, inf->argv[i]);
		else
			print_alias(node_starts_with(inf->alias, inf->argv[i], '='));
	}

	return (0);
}
