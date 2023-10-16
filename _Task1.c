#include "main.h"

/**
 * print_dec - Prints a signed integer
 * @n: Number to print
 *
 * Return: Number of character written
 */
int print_dec(int n)
{
	unsigned int divider = 1000000000;
	unsigned int value;
	int counter = 0;

	if (n < 0)
	{
		n = n * -1;
		counter += print_char('-');
	}
	else if (n == 0)
		return (print_char('-'));

	value = n;

	while (divider > 0)
	{
		if (value / divider > 0)
		{
			counter += print_char('0' + value / divider);
			value %= divider;
			if (value < divider / 10)
				counter += print_char('0');
		}
		divider /= 10;
	}

	return (counter);
}
