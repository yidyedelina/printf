#include "stdio.h"
#include "stdarg.h"
/**
 * printstr - a function that print string
 * @s: a string to be printed
 * Return: always integer
 */
int printstr(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		len++;
	}
	return (len);
}
/**
 * convert - convert any number to string
 * @num: the number need to convert
 * @base: the base
 * Return: a char*
 */
char *convert(unsigned int num, int base)
{
	static const char Representation[] = "0123456789ABCDEF";
	static char buffer[65];
	char *ptr;

	ptr = &buffer[64];
	*ptr = '\0';
	do {
		*--ptr =  Representation[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}
/**
 * _printf - a function to print a string
 * @format: a str
 * Return: the length of printed
 */
int _printf(const char *format, ...)
{
	const char *traverse;
	int len = 0;
	int i;
	char *s;

	if (format == NULL)
		return;
	va_list arg;

	va_start(arg, format);
	for (traverse = format; *traverse != '\0'; traverse++)
	{
		while (*traverse != '%' && *traverse != '\0')
		{
			putchar(*traverse);
			len++;
			traverse++;
		}
		traverse++;
		switch (*traverse)
		{
			case 'c':
				i = va_arg(arg, int);
				putchar(i);
				len++;
				break;
			case 's':
				s = va_arg(arg, char *);
				len = len + printstr(s);
				break;
			case '%':
				putchar('%');
				len++;
				break;
			default:
				putchar(*traverse);
		}
	}
	va_end(arg);
	return (len);
}
