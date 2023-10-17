#include "main.h"

/**
 * print_dec - Prints a signed integer
 * @n: Number to print
 * @bp: Pointer to local buffer
 *
 * Return: Number of character written
 */
int print_dec(long n, BUFFER *bp)
{
	unsigned long divider = 1000000000;
	unsigned long value;
	int counter = 0;

	if (n < 0)
	{
		n = n * -1;
		counter += print_char('-', bp);
	}
	else if (n == 0)
		return (print_char('0', bp));

	value = n;

	while (divider > 0)
	{
		if (value / divider > 0)
		{
			counter += print_char('0' + value / divider, bp);
			value %= divider;
			if (value < divider / 10)
				counter += print_char('0', bp);
		}
		divider /= 10;
	}

	return (counter);
}

