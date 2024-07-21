#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *separator = "";
	char *str;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separator, va_arg(ap, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(ap, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(ap, double));
				break;
			case 's':
				str = va_arg(ap, char*);
				if (str == NULL)
				{
					printf("%s(nil)", separator);
				}
				else
				{
					printf("%s%s", separator, str);
				}
				break;
			default:
				i++;
				continue;
		}
		
		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(ap);
}
