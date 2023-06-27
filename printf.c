#include "main.h"

/**
* _printf - printing variables based on specifiers
* @format: string that may contain formatting identifiers
* Return: int
*/
int _printf(const char *format, ...)
{
	int len, b_int, printed_char;
	arg_t *args;
	int i = 0;

	args = malloc(sizeof(arg_t));

	args->i = &i;
	args->precision = 0;
	args->width = 0;
	args->str_len = 0;
	args->flags = 0;
	args->str = malloc(sizeof(char) * B_SIZE);
	len = 0, b_int = 0, printed_char = 0;
	if (format == NULL || args->str == NULL)
		return (-1);
	va_start(args->vp, format);
	while (format[*args->i] != '\0')
	{
		if (format[*args->i] == '%')
		{
			write_str(args->str, &b_int);
			args->flags = set_flag(format, args->i);
			args->width = set_width(args->vp, format, args->i);
			args->precision = set_precision(args->vp, format, args->i);
			args->str_len = set_str_len(format, args->i);
			*(args->i) += 1;
			printed_char = _print(format, args);
			if (printed_char == -1)
				return (-1);
			len += printed_char;
		}
		else
		{
			args->str[b_int] = format[*args->i];
			b_int++;
			if (b_int ==  B_SIZE)
				write_str(args->str, &b_int);
			len++;
		}
		*(args->i) += 1;
	}
	va_end(args->vp);
	write_str(args->str, &b_int);
	free(args->str);
	free(args);
	return (len);
}
