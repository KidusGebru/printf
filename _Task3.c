#include "main.h"

/**
 * print_udec - Prints an unsigned integer
 * @n: Number to print
 * @bp: Pointer to local buffer
 *
 * Return: Number of character written
 */
int print_udec(unsigned int n, BUFFER *bp)
{
	unsigned int counter = 0;

	if (n == 0)
		return (print_char('0', bp));
	else if (n < 10)
		return (print_char(n + '0', bp));

	counter += print_udec(n / 10, bp);
	counter += print_char((n % 10) + '0', bp);

	return (counter);
}

/**
 * print_oct - Prints an octal representation of unsigned int
 * @n: Number to print
 * @bp: Pointer to local buffer
 *
 * Return: Number of character written
 */
int print_oct(unsigned int n, BUFFER *bp)
{
	unsigned int counter = 0;

	if (n == 0)
		return (print_char('0', bp));
	else if (n < 8)
		return (print_char(n + '0', bp));

	counter += print_oct(n / 8, bp);
	counter += print_char((n % 8) + '0', bp);

	return (counter);
}

/**
 * print_hex - Prints an unsigned int in small cap hexadecimal
 * @n: Number to print
 * @bp: Pointer to local buffer
 *
 * Return: Number of character written
 */
int print_hex(unsigned int n, BUFFER *bp)
{
	unsigned int counter = 0;
	char *syms = "0123456789abcdef";

	if (n == 0)
		return (print_char('0', bp));
	else if (n < 16)
		return (print_char(syms[n], bp));

	counter += print_hex(n / 16, bp);
	counter += print_char((n % 16) + '0', bp);

	return (counter);
}

/**
 * print_uhex - Prints an unsigned int in hexadecimal all caps
 * @n: Number to print
 * @bp: Pointer to local buffer
 *
 * Return: Number of character written
 */
int print_uhex(unsigned int n, BUFFER *bp)
{
	unsigned int counter = 0;
	char *syms = "0123456789ABCDEF";

	if (n == 0)
		return (print_char('0', bp));
	else if (n < 16)
		return (print_char(syms[n], bp));

	counter += print_uhex(n / 16, bp);
	counter += print_char((n % 16) + '0', bp);

	return (counter);
}

