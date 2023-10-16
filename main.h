#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#ifndef KIDRAH_PRINTF_H
#define KIDRAH_PRINTF_H


int _printf(const char *format, ...);
int print_char(char c);
int print_dec(int val);
int print_bin(unsigned int n);

#endif
