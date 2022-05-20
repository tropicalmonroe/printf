#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: has specifiers
 * Return: output string
 */

int _printf(const char *format, ...)
{
	int (*f)(va_list, flags_t *);
	const char *p;
	va_list arg;
	flags_t fl = {0, 0, 0,}

	register int co = 0;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format [1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &fl))
				p++;
			f = get_print(*p);
			count += (f)
				? f(arg, &fl)
				: _printf("%%%c", *p);
		}
		else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arg);
	return (count);
}
