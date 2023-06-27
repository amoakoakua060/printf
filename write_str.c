#include "main.h"

/**
* write_str - write characters of string
* @str: string
* @b_int: pointer to int
*/
void write_str(char *str, int *b_int)
{
	if (*b_int > 0)
		write(1, &str[0], *b_int);
	*b_int = 0;
}
