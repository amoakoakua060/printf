#include "main.h"

/**
 * print_i - print int
 * @ap: va_list
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @str_length: length specifiers
 * Return: int
 */
int print_i(
	va_list ap, char buffer[], int *i,
	int flags, int width, int precision,
	int str_length
)
{
	int integer, ibuf = 0;
	unsigned int in, temp, j, div, is_neg;

	UNUSED(i);
	UNUSED(precision);
	UNUSED(str_length);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);

	integer = va_arg(ap, int);
	is_neg = 0;
	in = integer;
	if (integer < 0)
	{
		in = integer * -1;
		ibuf = handl_buf(buffer, '-', ibuf);
		is_neg = 1;
	}

	temp = in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (j = 0; div > 0; div /= 10, j++)
		ibuf = handl_buf(buffer, ((in / div) % 10) + '0', ibuf);

	return (j + is_neg);
}
