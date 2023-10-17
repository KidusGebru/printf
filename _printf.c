#include "main.h"

/**
 * print_char - Prints a single character to standard IO
 * @c: The character
 * @bp: Pointer to local buffer
 *
 * Return: 1
 */
int print_char(char c, BUFFER *bp)
{
	if (bp->index >= BUFFER_SIZE - 1)
	{

		if (write(1, bp->loc, bp->index) == -1)
			return (-1);
		bp->index = 0;
	}

	bp->loc[bp->index] = c;
	bp->index += 1;
	return (1);
}

/**
 * print_str - Prints a string to standard IO
 * @str: Pointer to string
 * @bp: Pointer to local buffer
 *
 * Return: Number of chars written
 */
int print_str(char *str, BUFFER *bp)
{
	int counter = 0;

	if (str == NULL)
		return (print_str("(null)", bp));
	while (str[counter] != '\0')
	{
		print_char(str[counter], bp);
		counter++;
	}
	return (counter);
}

/**
 * _print - Calls appropriate function depending on the specifier
 * @arg_list: va_list type varible
 * @c: Format specifier
 * @bp: Pointer to local buffer
 *
 * Return: Length of printed characters
 */
int _print(va_list arg_list, char c, BUFFER *bp)
{
	switch (c)
	{
		case 'c':
			return (print_char(va_arg(arg_list, int), bp));
		case 's':
			return (print_str(va_arg(arg_list, char *), bp));
		case 'd':
		case 'i':
			return (print_dec(va_arg(arg_list, int), bp));
		case 'b':
			return (print_bin(va_arg(arg_list, unsigned int), bp));
		case 'u':
			return (print_udec(va_arg(arg_list, unsigned int), bp));
		case 'o':
			return (print_oct(va_arg(arg_list, unsigned int), bp));
		case 'x':
			return (print_hex(va_arg(arg_list, unsigned int), bp));
		case 'X':
			return (print_uhex(va_arg(arg_list, unsigned int), bp));
		default:
			return (print_char('%', bp) + print_char(c, bp));
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
	unsigned int c_count = 0, i = 0, flag = 0;
	va_list args;
	BUFFER buffer;
	BUFFER *bp = &buffer;

	bp->loc = malloc(BUFFER_SIZE);
	bp->index = 0;
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
				c_count += print_char('%', bp);
			}
			else
				flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;
			c_count += _print(args, format[i], bp);
		}
		else
			c_count += print_char(format[i], bp);
		i++;
	}
	va_end(args);

	if (bp->index > 0)
		write(1, bp->loc, bp->index);
	bp->index = 0;
	free(bp->loc);
	return (c_count);
}

