#include "main.h"
#include <stdio.h>
/**
 * print_dec_r - Recursively print digits of a number
 * @n: Number
 * @bp: Pointr to local buffer
 *
 * Return: Number of character written
 */
int print_dec_r(long int n, BUFFER *bp)
{
	int counter = 0;

	if (n <= 0)
		return (0);

	counter += print_dec_r(n / 10, bp);
	counter += print_char((n % 10) + '0', bp);

	return (counter);
}


/**
 * print_dec - Prints a signed integer
 * @n: Number to print
 * @bp: Pointer to local buffer
 *
 * Return: Number of character written
 */
int print_dec(long int n, BUFFER *bp)
{
	int counter = 0, l_digit;

	printf("\n --- %ld ---\n", n);
	if (n < 0)
		counter += print_char('-', bp);
	else if (n == 0)
		return (print_char('0', bp));

	l_digit = n % 10;
	if (l_digit < 0)
		l_digit = -l_digit;

	n /= 10;
	if (n < 0)
		n = -n;

	counter += print_dec_r(n, bp);
	counter += print_char(l_digit + '0', bp);

	return (counter);
}

