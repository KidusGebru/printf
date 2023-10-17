#ifndef KIDRAH_PRINTF_H
#define KIDRAH_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * struct buf - Structure for holding local buffer related variables
 * @loc: Pointer to location of buffer in memory
 * @index: Current buffer position
 */
typedef struct buf
{
	char *loc;
	unsigned int index;
} BUFFER;

int _printf(const char *format, ...);
int print_char(char c, BUFFER *bp);
int print_str(char *str, BUFFER *bp);
int print_dec(int val, BUFFER *bp);
int print_bin(unsigned int n, BUFFER *bp);
int print_udec(unsigned int n, BUFFER *bp);
int print_oct(unsigned int n, BUFFER *bp);
int print_hex(unsigned int n, BUFFER *bp);
int print_uhex(unsigned int n, BUFFER *bp);

#endif

