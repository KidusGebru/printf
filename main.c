#include <stdio.h>
#include "main.h"

int main(void)
{
	int i;
	i = _printf("%c is the %c6 \nstart of string %s\n", 'Y', "Yemane");
	printf("\n ---------- %d chars --------\n", i);
	return (0);
}
