#include "main.h"

/**
 * print_rev - writes the str in reverse
 * @ap: va_list
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @str_length: length specifiers
 * Return: number of chars printed.
 */
int print_rev(
	va_list ap, char buffer[], int *i,
	int flags, int width, int precision,
	int str_length
)
{
	char *str;
	unsigned int n_i;
	int j = 0, ibuf = 0;
	char nill[] = "(llun)";

	UNUSED(i);
	UNUSED(precision);
	UNUSED(str_length);
	UNUSED(width);
	UNUSED(flags);

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		for (n_i = 0; nill[n_i]; n_i++)
			ibuf = handl_buf(buffer, nill[n_i], ibuf);
		return (6);
	}

	for (n_i = 0; str[n_i]; n_i++)
		;
	j = n_i - 1;
	for (; j >= 0; j--)
		ibuf = handl_buf(buffer, str[j], ibuf);

	return (n_i);
}
