#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings with a separator
 * @separator: the string to be printed between the strings
 * @n: the number of strings passed to the function
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *strg;

	va_list ap;
	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		strg = va_arg(ap, char*);

		if (strg == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", strg);
		}

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(ap);
}
