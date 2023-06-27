#include "main.h"

/**
 * set_width - set flags
 * @ap: argument pointer
 * @format: format string
 * @i: pointer to integer
 *
 * Description: Set the flags as integers
 *
 * Return: int
 */
int set_width(va_list ap, const char *format, int *i)
{
	int j = *i + 1, width = 0;

	for (; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			width *= 10;
			width = width + (format[j] - '0');
		}
		else if (format[j] == '*')
		{
			width = va_arg(ap, int);
			j++;
			break;
		}
		else
			break;
	}
	*i = j - 1;
	return (width);
}
