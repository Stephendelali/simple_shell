#include "shell.h"

/**
 **_strncpy - dupicatiin of stirngs
 *@dest: the destination
 *@src: string source
 *@num: number of copied charactterd
 *Return: value
 */
char *_strncpy(char *dest, char *src, int num)
{
	int k, m;
	char *s = dest;

	k = 0;
	while (src[k] != '\0' && k < num - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < num)
	{
		m = k;
		while (m < num)
		{
			dest[m] = '\0';
			m++;
		}
	}
	return (s);
}

/**
 **_strncat - joins two strings together
 *@dest: 1st string
 *@src: 2nd string
 *@num: the maximum number of bytes that can be used
 *Return: joined strings
 */
char *_strncat(char *dest, char *src, int num)
{
	int k, m;
	char *s = dest;

	k = 0;
	m = 0;
	while (dest[k] != '\0')
		k++;
	while (src[m] != '\0' && m < num)
	{
		dest[k] = src[m];
		k++;
		m++;
	}
	if (m < num)
		dest[k] = '\0';
	return (s);
}

/**
 **_strchr - helps in locating characters
 *@p: string to be parsed
 *@l: character needed
 *Return: (p) a pointer to the memory area s
 */
char *_strchr(char *p, char l)
{
	do {
		if (*p == l)
			return (p);
	} while (*p++ != '\0');

	return (NULL);
}
