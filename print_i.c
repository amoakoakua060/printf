#include "main.h"

/**
 * reverse - reverse string
 * @str: buffer
 * @length: length of string
 */
void reverse(char *str, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/**
 * _itoa - convert number to integer
 * @num: integer
 * @str: buffer
 */
void _itoa(int num, char *str)
{
	int i = 0;
	int isNegative = 0;

	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';

	reverse(str, i);
}

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
	int integer, ibuf = 0, j = 0;
	unsigned int in, is_neg;
	char buf[B_SIZE];

	UNUSED(i);
	UNUSED(precision);
	UNUSED(str_length);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);

	integer = va_arg(ap, int);
	is_neg = 0;
	if (integer < 0)
	{
		in = integer * -1;
		ibuf = write(1, "-", 1);
		is_neg = 1;
	}
	else
		in = integer;

	_itoa(in, buf);
	ibuf = 0;
	while (buf[ibuf])
		ibuf++;
	j =  (ibuf + is_neg);
	write_str(buf, &ibuf);
	return (j);
}
