#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _print - Print a single argument
 * @arg_list: va_list type varible
 * @c: Format specifier
 *
 * Return: Length of printed characters
 */
int _print(va_list arg_list, char c)
{
	char *str;
	int i = 0;

	switch (c)
	{
		case 'c':
			printf("%c", va_arg(arg_list, int));
			i += 1;
			break;
		case 's':
			str = va_arg(arg_list, char *);
			if (str != NULL)
			{
				printf("%s", str);
				i += strlen(str);
			}
			break;
		default:
			printf("%c", c);
			i += 1;
	}
	return (i);
}

/**
 * _printf - Prints arguments to standard IO according to format string
 * @format: Format specifiers contained in a string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned char c_count = 0, i = 0;
	va_list args;
	int flag = 0;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
			flag = 1;
		else if (flag == 1)
		{
			flag = 0;
			c_count += _print(args, format[i]);
		}
		else
		{
			printf("%c", format[i]);
			c_count += 1;
		}
		i++;
	}
	va_end(args);
	return (c_count);
}
