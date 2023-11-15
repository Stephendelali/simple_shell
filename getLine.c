#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @inf: parameter
 * @buf: buffer add
 * @len: len var add.
 *
 * Return: read bytes
 */
ssize_t input_buf(info_t *inf, char **buf, size_t *len)
{
	ssize_t l = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		l = getline(buf, &len_p, stdin);
#else
		l = _getline(inf, buf, &len_p);
#endif
		if (l > 0)
		{
			if ((*buf)[l - 1] == '\n')
			{
				(*buf)[l - 1] = '\0';
				l--;
			}
			inf->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(inf, *buf, inf->histcount++);
			{
				*len = l;
				inf->cmd_buf = buf;
			}
		}
	}
	return (l);
}

/**
 * get_input -  line minus  newline
 * @inf: parameter
 *
 * Return: read bytes
 */
ssize_t get_input(info_t *inf)
{
	static char *buf;
	static size_t i, k, len;
	ssize_t l = 0;
	char **buf_p = &(inf->arg), *m;

	_putchar(BUF_FLUSH);
	l = input_buf(inf, &buf, &len);
	if (l == -1)
		return (-1);
	if (len)
	{
		k = i;
		m = buf + i;

		check_chain(inf, buf, &k, i, len);
		while (k < len)
		{
			if (is_chain(inf, buf, &k))
				break;
			k++;
		}

		i = k + 1;
		if (i >= len)
		{
			i = len = 0;
			inf->cmd_buf_type = CMD_NORM;
		}

		*buf_p = m;
		return (_strlen(m));
	}

	*buf_p = buf;
	return (l);
}

/**
 * read_buf - buffer reader
 * @info: parameter
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t l = 0;

	if (*i)
		return (0);
	l = read(info->readfd, buf, READ_BUF_SIZE);
	if (l >= 0)
		*i = l;
	return (l);
}

/**
 * _getline - gets next line of input
 * @inf: parameter struct
 * @ptr: address of pointer to buffer
 * @length: preallocated size
 *
 * Return: l
 */
int _getline(info_t *inf, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t l = 0, s = 0;
	char *m = NULL, *new_p = NULL, *c;

	m = *ptr;
	if (m && length)
		s = *length;
	if (i == len)
		i = len = 0;

	l = read_buf(inf, buf, &len);
	if (l == -1 || (l == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(m, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (m ? free(m), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	m = new_p;

	if (length)
		*length = s;
	*ptr = m;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
