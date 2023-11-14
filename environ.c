#include "shell.h"

/**
 * _myenv - prints environment
 * @inf: Arguments structure.
 * Return:  0
 */
int _myenv(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @inf: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *inf, const char *name)
{
	list_t *node = inf->env;
	char *l;

	while (node)
	{
		l = starts_with(node->str, name);
		if (l && *l)
			return (l);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Set up a fresh environment variable.,
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenvi - Remove an environment variable
 * @inf: for maintenance of constant funtion protocols.
 *  Return: Always 0
 */
int _myunsetenvi(info_t *inf)
{
	int i;

	if (inf->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= inf->argc; i++)
		_unsetenv(inf, inf->argv[i]);

	return (0);
}

/**
 * populate_env_list -  used to populate lists
 * @inf: Potential arg. structure.
 * Return: Always 0
 */
int populate_env_list(info_t *inf)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	inf->env = node;
	return (0);
}
