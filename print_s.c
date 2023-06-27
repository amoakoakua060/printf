#include "main.h"

/**
 * print_s - print string
 * @ap: va_list
 * @buffer: string buffer
 * @i: current index
 * @flags: flag specifiers
 * @width: width specifiers
 * @precision: precision specifiers
 * @str_length: length specifiers
 * Return: int
 */
int print_s(
	va_list ap, char buffer[], int *i, int flags,
	int width, int precision, int str_length
)
{
	char *str, padding = ' ';
	int j, printed_chars = 0, len = 0;

	UNUSED(str_length);
	UNUSED(i);
	UNUSED(buffer);
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	len = _strlen(str);
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		buffer[B_SIZE - 1] = '\0';
		for (j = 0; j < width - len - 1; j++)
			buffer[B_SIZE - 2 - j] = padding;
		j--;
		if (flags & F_MINUS)
		{
			printed_chars = write(1, &str[0], len);
			printed_chars += write(1, &str[B_SIZE - 2 - j], width);
		}
		else
		{
			printed_chars = write(1, &str[B_SIZE - 2 - j], width);
			printed_chars += write(1, &str[0], len);
		}
	}
	else
		printed_chars = write(1, &str[0], len);

	return (printed_chars);
}
