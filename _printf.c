#include <stdarg.h> /* for va_list, va_start, va_arg, va_end */
#include "main.h"
#include <stddef.h>
/**
 * _printf - Printf function
 * @format: format argument
 * Return:  chars values.
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0; /* to keep track of the number of characters printed*/

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s != '\0')
				{
					_putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
