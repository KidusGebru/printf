#include "main.h"

/**
 * print_bin - Prints binary representation of unsigned int
 * @n: Number to print
 *
 * Return: Number of character written
 */
int print_bin(unsigned int n)
{
	int counter = 0;

	if (n < 2)
		return (print_char(n + '0'));

	counter += print_bin(n / 2);
	counter += print_char((n % 2) + '0');

	return (counter);
}
