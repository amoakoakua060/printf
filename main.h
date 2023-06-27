#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define UNUSED(a) (void)(a)

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define LONG_LENGTH 1
#define SHORT_LENGTH 2

#define B_SIZE 1024

/**
* struct f_spec - struct for specifiers
* @specifier: specific specifier
* @fn: function associated with the specifier
*
* Description: this struct helps us assign a function
* to a specifier
*/
struct f_spec
{
	char specifier;
	int (*fn)(va_list, char [], int *, int, int, int, int);
};

/**
* f_spec_t - typedef struct for specifiers
*/
typedef struct f_spec f_spec_t;

/**
* struct arg_s - struct for arguments
* @str: buffer string
* @vp: va_list
* @flags: integer
* @precision: integer
* @width: integer
* @str_len: integer
*/
typedef struct arg_s
{
	char *str;
	va_list vp;
	int *i;
	int flags;
	int precision;
	int width;
	int str_len;
} arg_t;

int _printf(const char *format, ...);
int _print(const char *format, arg_t *args);

int print_c(va_list, char [], int *, int, int, int, int);
int print_s(va_list, char [], int *, int, int, int, int);
int print_per(va_list, char [], int *, int, int, int, int);
int print_i(va_list, char [], int *, int, int, int, int);
int print_b(va_list, char [], int *, int, int, int, int);
int print_f(va_list, char [], int *, int, int, int, int);
int print_rev(va_list, char [], int *, int, int, int, int);

int set_flag(const char *format, int *i);
int set_width(va_list ap, const char *format, int *i);
int set_precision(va_list ap, const char *format, int *i);
int set_str_len(const char *format, int *i);

int is_digit(char c);
int _strlen(char *s);
long int cast_number(long int, int);
void write_str(char *str, int *b_int);
int handl_buf(char *buf, char c, int ibuf);

#endif /**MAIN_H*/
