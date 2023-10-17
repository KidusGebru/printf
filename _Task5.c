#include "main.h"

/**
 * print_cstr - Prints a string with non printable chars converted to hex
 * @str: Pointer to string
 * @bp: Pointer to local buffer
 *
 * Return: Number of chars written
 */
int print_cstr(char *str, BUFFER *bp)
{
	int counter = 0, i = 0;

	if (str == NULL)
		return (print_str("(nil)", bp));
	while (str[i] != '\0')
	{
		if (str[i] > 126 || str[i] < 32)
		{
			counter += print_str("\\x", bp);
			if (str[i] < 17)
				counter += print_char('0', bp);
			counter += print_uhex(str[i], bp);
		}
		else
			counter += print_char(str[i], bp);
		i++;
	}
	return (counter);
}
