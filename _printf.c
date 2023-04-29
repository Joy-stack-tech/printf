#include "main.h"
/**
 * _printf - printf function that sends a formatted string to output
 * @format: thr format used
 * Return: the value of the printed char
*/
int _printf(const char *format, ...)
{
	int j, print = 0, print_chars = 0;
	int width, flags, size, precision, buff_ind = 0;
	va_list inc;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(inc, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
		}
		else if (buff_ind == BUFF_SIZE)
		{
			print_buffer(buffer, &buff_ind);
			print_chars++;

			print_buffer(buffer, &buff_ind);
			width = get_width(format, &j, inc);
			flags = get_flags(format, &j);
			size = get_size(format, &j);
			++j;
			precision = get_precision(format, &j, inc);
			print = handle_print(format, &j, inc, buffer,
			width, flags, size, precision);
		}
		if (print == -1)
		{
			return (-1);
			print_chars += print;
		}
	}
		print_buffer(buffer, &buff_ind);
		va_end(inc);

		return (print_chars);
}

