#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: has specifiers
 * Return: output string
 */

int _printf(const char *format, ...)
{
	int (*f)(va_list, flags_t *);
	const char *s;
	va_list arg;
	flags_t fl = {0, 0, 0,}

	register int co = 0;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format [1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (s = format; *s; s++)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*s, &fl))
				s++;
			f = get_print(*s);
			count += (f)
				? f(arg, &fl)
				: _printf("%%%c", *s);
		}
		else
			count += _putchar(*s);
	}
	_putchar(-1);
	va_end(arg);
	return (count);
}
