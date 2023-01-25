#include "main.h"

/****************** PRINT CHAR **********************/

/**
  * print_char - prints character
  * @types: List of arguments
  * @buffer: Buffer array to handle print
  * @flags: Calculates ative flags
  * @width: width
  * @precision: precision specification
  * @size: size specifier
  *
  * Return: Number of chars printed.
  */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/*********************** PRINT A STRING ********************/
/**
  * print_string - prints a string
  * @types: List of arguments
  * @buffer: buffer array to handle print
  * @flags: calculate active flags
  * @width: get width.
  * @precision: precision specifier
  * @size: size specifier.
  *
  * Return: string
  */
int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width)l
		}
	}
	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN **********************/
/**
  * print_percent - print a percent sign
  * @types: list of arguments
  * @buffer: buffer array to handle print
  * @flags: calculates active flags
  * @width: width
  * @precision: Precision specification
  * @size: size specifier
  *
  * Return: Number of chars printed
  */
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));

}

/****************** PRINT INT ************************/
/**
  * print_int - prints integer
  * @types: List of arguments
  * @buffer: buffer array to handle print
  * @flags: calculate active flags
  * @width: width
  * @precision: precision specification
  * @size: size of specifier
  *
  * Return: number of chars printed
  */

