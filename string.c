#include "shell.h"

/**
 * _strlen - returns string length
 * @l: the string length to bebbb checked
 *
 * Return: in t length
 */
int _strlen(char *l)
{
	int i = 0;

	if (!l)
		return (0);

	while (*l++)
		i++;
	return (i);
}

/**
 * _strcmp - compares two strangs.
 * @s1: 1st strang
 * @s2: 2nd strang
 *
 * Return:   s1 < s2,  if s1 > s2, or s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle
 * @haystack: search string
 * @needle: substring to find
 * Return: address of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - adds strings
 * @dest: buffer location
 * @src: buffer source
 *
 * Return: pointer destination to buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
