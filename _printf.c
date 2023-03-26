#include "main.h"
<<<<<<< HEAD
/**
 * _printf - Print all this parameters
 * @format: input
 *
 * Description: function that prints output
 *
 * Return: The output character or num
 */
int _printf(const char *format, ...)
{
	int x = 0, o_p = 0;
	char *ptr = (char *) format, *output_p;
	int (*ptr_func)(va_list, char *, int);
	va_list vlist;

	if (!format)
		return (-1);
	va_start(vlist, format);
	output_p = malloc(sizeof(char) * SIZE);
	if (!output_p)
		return (1);
	while (format[x])
	{
		if (format[x] != '%')
			output_p[o_p] = format[x], o_p++;
		else if (s_trlen(ptr) != 1)
		{
			ptr_func = format_type(++ptr);
			if (!ptr_func)
				output_p[o_p] = format[x], o_p++;
			else
				o_p = ptr_func(vlist, output_p, o_p), x++;
		}
		else
			o_p = -1;
		x++, ptr++;
	}
	va_end(vlist);
	write(1, output_p, o_p);
	free(output_p);
	return (o_p);
}

=======

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format argument
 * Return:  chars values.
 */
int _printf(const char *format, ...)
{

int i, printed = 0, printed_chars = 0;

int flags, width, precision, size, buff_ind = 0;

va_list list;

char buffer[BUFF_SIZE];

if (format == NULL)

return (-1);

va_start(list, format);

for (i = 0; format && format[i] != '\0'; i++)

{

if (format[i] != '%')

{

buffer[buff_ind++] = format[i];

if (buff_ind == BUFF_SIZE)

print_buffer(buffer, &buff_ind);

/* write(1, &format[i], 1);*/

printed_chars++;

}

else

{

print_buffer(buffer, &buff_ind);

flags = get_flags(format, &i);

width = get_width(format, &i, list);

precision = get_precision(format, &i, list);

size = get_size(format, &i);

++i;

printed = handle_print(format, &i, list, buffer,

flags, width, precision, size);

if (printed == -1)

return (-1);

printed_chars += printed;

}

}



print_buffer(buffer, &buff_ind);



va_end(list);



return (printed_chars);

}



/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{

if (*buff_ind > 0)

write(1, &buffer[0], *buff_ind);



*buff_ind = 0;

}
>>>>>>> e8e97b571041df0820ff78f915356f53fcccbd26
