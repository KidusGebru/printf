#include "main.h"

/**
 * print_char - Prints a single character to standard IO
 * @c: The character
 *
 * Return: 1
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Prints a string to standard IO
 * @str: Pointer to string
 *
 * Return: Number of chars written
 */
int print_str(char *str)
{
	int counter = 0;

	if (str == NULL)
		return (print_str("(null)"));
	while (str[counter] != '\0')
	{
		print_char(str[counter]);
		counter++;
	}
	return (counter);
}

/**
 * _print - Calls appropriate function depending on the specifier
 * @arg_list: va_list type varible
 * @c: Format specifier
 *
 * Return: Length of printed characters
 */
int _print(va_list arg_list, char c)
{
	switch (c)
	{
		case 'c':
			return (print_char(va_arg(arg_list, int)));
		case 's':
			return (print_str(va_arg(arg_list, char *)));
		case 'd':
		case 'i':
			return (print_dec(va_arg(arg_list, int)));
		case 'b':
			return (print_bin(va_arg(arg_list, unsigned int)));
		default:
			return (print_char('%') + print_char(c));
	}
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

	if (format == NULL || strcmp(format, "%\0") == 0)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (flag == 1)
			{
				flag = 0;
				c_count += print_char('%');
			}
			else
				flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;
			c_count += _print(args, format[i]);
		}
		else
			c_count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (c_count);
}
