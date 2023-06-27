#include "main.h"

/**
 * cast_number - casting number
 * @num: Number params
 * @size: type being casted.
 * Return: long int
 */
long int cast_number(long int num, int size)
{
	if (size == LONG_LENGTH)
		return (num);
	else if (size == SHORT_LENGTH)
		return ((short)num);

	return ((int)num);
}
