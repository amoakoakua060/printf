#include "main.h"

/**
 * set_flag - set flags as integer
 * @format: format string
 * @i: pointer to integer
 * Return: int
 */
int set_flag(const char *format, int *i)
{
	const char flags_char[] = "-+0# ";
	const int flags_int[] = {
		F_MINUS, F_PLUS,
		F_ZERO, F_HASH,
		F_SPACE, 0
	};
	int j, k, flags = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		for (k = 0; flags_char[k] != '\0'; k++)
		{
			if (flags_char[k] == format[j])
			{
				flags |= flags_int[k];
				break;
			}
		}

		if (flags_char[k] == '\0')
			break;
	}

	*i = j - 1;
	return (flags);
}
