#include "main.h"

/**
 * print_point - Prints a pointer
 * @p: The pointer itself
 * @bp: Pointer to local buffer
 *
 * Return: Number of chars written
 */
int print_point(void *p, BUFFER *bp)
{
	unsigned long int ptr;

	if (p == NULL)
		return (print_str("(null)", bp));

	ptr = (unsigned long int)p;

	print_str("0x", bp);
	return (2 + print_hex(ptr, bp));
}

