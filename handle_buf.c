#include "main.h"

/**
 * handl_buf - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: charcter to concatenate
 * @ibuf: index of buffer pointer
 * Return: index of buffer pointer.
 */
int handl_buf(char *buf, char c, int ibuf)
{
	if (ibuf == 1024)
	{
		write_str(buf, &ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}
