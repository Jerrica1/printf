#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
  * _printf - this function is a replica of the standard printf
  * function in string.
  * @format: first argument.
  * @...: Variable arguments.
  *
  * Return: Printed chracters.
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
			buffer[buf_inde++] = format[i];
			if (buf_ind == BUF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_char++;
		}
		else
		{
			print_buffer(buffer, &buf_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			i++;
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
  * print_buffer - prints the cotents of the buffer if it exist.
  * @buffer: Array of chars
  * @buff_ind: Index at which to add next char, represents the length.
  */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
=======
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * find_function - function that finds formats for _printf
 * calls the corresponding function.
 * @format: format (char, string, int, decimal)
 * Return: NULL or function associated ;
 */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"r", print_rev},
		{"b", print_bin},
		{"u", print_unsig},
		{"o", print_octal},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (find_f[i].sc)
	{
		if (find_f[i].sc[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}
/**
 * _printf - function that produces output according to a format.
 * @format: format (char, string, int, decimal)
 * Return: size the output text;
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cprint += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (cprint);
>>>>>>> 6998b1de32540e6605fa82ea421fa63941b40e41
}
