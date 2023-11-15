#include "shell.h"

/**
 * list_len - shows length of list
 * @l: first node pointer
 * Return: size of list
 */
size_t list_len(const list_t *l)
{
	size_t i = 0;

	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints list
 * @l: pointer to first node
 * Return: size of list
i */
size_t print_list(const list_t *l)
{
	size_t i = 0;

	while (l)
	{
		_puts(convert_number(l->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(l->str ? l->str : "(nil)");
		_puts("\ni");
		l = l->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node
 * @node: pointer head
 * @prefix: string to match
 * @c: matches next character after prefix
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
