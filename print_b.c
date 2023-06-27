#include "main.h"

/**
 * print_b - print binary
 * @ap: va_list
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @str_length: length specifiers
 * Return: int
 */
int print_b(
	va_list ap, char buffer[], int *i, int flags,
	int width, int precision, int str_length
)
{
	unsigned int n, j = B_SIZE - 2;

	UNUSED(width);
	UNUSED(i);
	UNUSED(str_length);
	UNUSED(flags);
	UNUSED(precision);

	n = va_arg(ap, unsigned int);
	buffer[B_SIZE - 1] = '\0';

	if (n == 0)
		buffer[j--] = '0';

	while (n != 0)
	{
		buffer[j--] = (n % 2) + '0';
		n /= 2;
	}
	j++;
	return (write(1, &buffer[j], B_SIZE - 1 - j));
}
