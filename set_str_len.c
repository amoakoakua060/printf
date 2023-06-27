#include "main.h"

/**
 * set_str_len - set length
 * @format: string formater
 * @i: format index
 * Return: int
 */
int set_str_len(const char *format, int *i)
{
	int j = *i + 1, str_len = 0;

	if (format[j] == 'l')
	{
		str_len = LONG_LENGTH;
		*i = j;
	}
	else if (format[j] == 'h')
	{
		str_len = SHORT_LENGTH;
		*i = j;
	}

	return (str_len);
}
