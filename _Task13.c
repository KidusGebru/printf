#include "main.h"

/**
 * print_rstr - Prints a string in a reverse
 * @str: Pointer to string
 * @index: Index of positino in the string
 * @bp: Pointer to local buffer
 *
 * Return: Number of chars written
 */
int print_rstr(char *str, int index, BUFFER *bp)
{
	int counter = 0;

	if (str == NULL)
		return (print_str("(nil)", bp));

	if (str[index] == '\0')
		return (0);
	counter += print_rstr(str, index + 1, bp);
	counter += print_char(str[index], bp);

	return (counter);
}
