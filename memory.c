#include "shell.h"

/**
 * bfree - frees  pointer
 * @ptr: address to frred pointer 
 *
 * Return: 1 = freed , 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
