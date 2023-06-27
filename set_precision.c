#include "main.h"

/**
 * set_precision - set precision
 * @ap: argument pointer
 * @format: format string
 * @i: pointer to integer
 * Return: int
 */
int set_precision(va_list ap, const char *format, int *i)
{
	int j = *i + 1, p = -1;

	if (format[*i] != '.')
		return (p);

	p = 0;
	for (; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			p *= 10;
			p = p + (format[j] - '0');
		}
		else if (format[j] == '*')
		{
			p = va_arg(ap, int);
			j++;
			break;
		}
		else
			break;
	}
	*i = j - 1;
	return (p);
}
