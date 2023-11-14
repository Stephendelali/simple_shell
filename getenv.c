#include "shell.h"

/**
 * get_environ - returns the string array
 * @inf: Structure for potential arguments.
 * Return: 0
 */
char **get_environ(info_t *inf)
{
	if (!inf->environ || inf->env_changed)
	{
		inf->environ = list_to_strings(inf->env);
		inf->env_changed = 0;
	}

	return (inf->environ);
}

/**
 * _unsetenv -for removing environmental variailes
 * @inf: maintain  constant function prototype.
 *  Return: 1 to remove , else 0
 * @var: env var property
 */
int _unsetenv(info_t *inf, char *var)
{
	list_t *node = inf->env;
	size_t i = 0;
	char *m;

	if (!node || !var)
		return (0);

	while (node)
	{
		m = starts_with(node->str, var);
		if (m && *m == '=')
		{
			inf->env_changed = delete_node_at_index(&(inf->env), i);
			i = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (inf->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info:  maintain constant prototype.
 * @var: en var sting prop.
 * @value: en var value
 *  Return: 0 always
 */
int _setenv(info_t *inf, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *m;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = inf->env;
	while (node)
	{
		m = starts_with(node->str, var);
		if (m && *m == '=')
		{
			free(node->str);
			node->str = buf;
			inf->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(inf->env), buf, 0);
	free(buf);
	inf->env_changed = 1;
	return (0);
}
