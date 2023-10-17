#include "main.h"

/**
 * getRot - Gets the 13th letter after
 * @r: The alphabet string
 * @d: Alphabet rotated by 13
 * @ch: Character to rotate
 *
 * Return: Character after rotating by 13
 */
char getRot(char *r, char *d, char ch)
{
	int i = 0;

	while (*(r + i) != '\0')
	{
		if (*(r + i) == ch)
		{
			ch = *(d + i);
			break;
		}
		i++;
	}
	return (ch);
}

/**
 * print_rot13 - Prints a string in ROT13 cipher
 * @str: The string
 * @bp: Pointer to local buffer
 *
 * Return: Pointer to rotated string
 */
int print_rot13(char *str, BUFFER *bp)
{
	int counter = 0;
	char *ref = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *indx = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (str == NULL)
		return (print_str("(nil)", bp));

	while (str[counter] != '\0')
		counter += print_char(getRot(ref, indx, str[counter]), bp);

	return (counter);
}

