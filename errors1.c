#include "shell.h"

/**
 * _erratoi - changes strings to int
 * @d: change string
 * Return: 0 for converted numbers
 */
int _erratoi(char *d)
{
	int i = 0;
	unsigned long int result = 0;

	if (*d == '+')
		d++;
	for (i = 0;  d[i] != '\0'; i++)
	{
		if (d[i] >= '0' && d[i] <= '9')
		{
			result *= 10;
			result += (d[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - shows error
 * @inf:  parameter , info struct
 * @estr: string for exact error
 * Return: 0 fro succes
 */
void print_error(info_t *inf, char *estr)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - prints numbers
 * @in: value input
 * @fd: the filedescriptor
 *
 * Return: number of characters printed
 */
int print_d(int in, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (in < 0)
	{
		_abs_ = -in;
		__putchar('-');
		count++;
	}
	else
		_abs_ = in;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @nu: num
 * @b: the base
 * @flags: arg flags
 *
 * Return: string
 */
char *convert_number(long int nu, int b, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = nu;

	if (!(flags & CONVERT_UNSIGNED) && nu < 0)
	{
		n = -nu;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - replaces first instance
 * @buf: ddress string modification
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int v;

	for (v = 0; buf[v] != '\0'; v++)
		if (buf[v] == '#' && (!v || buf[v - 1] == ' '))
		{
			buf[v] = '\0';
			break;
		}
}
