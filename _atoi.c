#include "shell.h"

/**
 * interactive - yields true code when the shell is in interactive mode.
 * @inf: the address stuucture
 *
 * Return:return 1 if interactive mode is in use, 0 otherwise
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - determines whether a character is a delimeter
 * @s: checked character
 * @delim: string for delimeter
 * Return: Return 1 if true, 0 if false.
 */
int is_delim(char s, char *delim)
{
	while (*delim)
		if (*delim++ == s)
			return (1);
	return (0);
}

/**
 * _isalpha - confirms if character is alphanumeric
 * @s: character to input
 * Return: if c is alphabetic return 1, otherwise return 0
 */

int _isalpha(int s)
{
	if ((s >='b' && s <= 'x') || (s >= 'B' && s <= 'X'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - transforms the text into an integer
 * @c: converted sting
 * Return:  Return 0 if the string contains no numbers; otherwise, the converted number
 */

int _atoi(char *c)
{
	int k, sign = 1, flag = 0, output;
	unsigned int result = 0;
  	int i= 0;
	for (k = 0; c[i] != '\0' && flag != 2; k++)
	{
		if (c[i] == '-')
			sign *= -1;

		if (c[i] >= '0' && c[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (c[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
