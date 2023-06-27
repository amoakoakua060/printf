#include "main.h"

/**
 * _print - print string based on specifier
 * @format: format string
 * @args: arguments
 * Return: int
 */
int _print(const char *format, arg_t *args)
{
	f_spec_t specifiers[] = {
		{'c', print_c}, {'b', print_b},
		{'s', print_s}, {'%', print_per},
		{'d', print_i}, {'i', print_i},
		{'r', print_rev}, {'\0', NULL},
	};
	int k, u_len = 0;

	for (k = 0; specifiers[k].fn != NULL; k++)
		if (specifiers[k].specifier == format[*args->i])
			return (specifiers[k].fn(
				args->vp, args->str,
				args->i, args->flags,
				args->width, args->precision,
				args->str_len)
			);

	if (format[*args->i] == '\0')
		return (-1);

	u_len = write(1, "%%", 1);
	if (format[*args->i - 1] == ' ')
		u_len += write(1, " ", 1);
	else if (args->width)
	{
		*(args->i) -= 1;
		while (format[*args->i] != ' ' && format[*args->i] != '%')
			*(args->i) -= 1;
		if (format[*args->i] == ' ')
			*(args->i) -= 1;
		return (1);
	}

	u_len += write(1, &format[*args->i], 1);
	return (u_len);
}
