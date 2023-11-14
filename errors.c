#include "shell.h"

/**
 *_eput - pronts sting that has been input
 * @str: print our siring
 *
 * Return: 0
 */
void _eput(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputcha - stderr character
 * @k: print character
 *
 * Return: success =1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputcha(char k)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (k != BUF_FLUSH)
		buf[i++] = k;
	return (1);
}

/**
 * _putf - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 */
int _putf(char k, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (k != BUF_FLUSH)
		buf[i++] = k;
	return (1);
}

/**
 *_putsfd= - outputs the input string.
 * @str: putput string
 * @fd: the filedescriptor
 *
 * Return: number of chars
 */
int _putsf(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
