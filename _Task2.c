#include "main.h"

/**
 * print_bin - Prints binary representation of unsigned int
 * @n: Number to print
 * @bp: Pointer to local buffer
 *
 * Return: Number of character written
 */
int print_bin(unsigned int n, BUFFER *bp)
{
	int counter = 0;

	if (n < 2)
		return (print_char(n + '0', bp));

	counter += print_bin(n / 2, bp);
	counter += print_char((n % 2) + '0', bp);

	return (counter);
}

