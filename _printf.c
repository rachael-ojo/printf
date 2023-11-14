#include <stdarg.h>
#include <stdio.h>
-printf.c
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
/**
 * _printf - function that produces output according to a format
 * @format: is a character string with format specifier
 * Return: the number of the printed characters
 */
int _printf(const char *format, ...)
{
	if (format != NULL)
	{
		int count = 0, i;
		int (*ba)(va_list);
		va_list args;

		va_start(args, format);
		i = 0;
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		while (format != NULL && format[i] != '\0')
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '%')
				{
					count += _putchar(format[i]);
					i += 2;
				}
				else
				{
					ba = get_func(format[i + 1]);
					if (ba)
						count += ba(args);
					else
						count = _putchar(format[i]) + _putchar(format[i + 1]);
					i += 2;
				}
			}
			else
			{
				count += _putchar(format[i]);
				i++;
			}
		}
		va_end(args);
		return (count);
	}
	return (-1);
}

-putchar.c
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
