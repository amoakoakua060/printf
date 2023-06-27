#include "main.h"

/**
 * _strlen - get length of string
 * @s: array of chars
 * Return: int
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
