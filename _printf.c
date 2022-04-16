#include "stdio.h"
#include "main.h"
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
	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	for (traverse = format; *traverse != '\0'; traverse++)
	{
		while (*traverse != '%' && *traverse != '\0')
		{
			if (*traverse == '\0')
				return (-1);
			putchar(*traverse);
			len++;
			traverse++;
		}
		if (*traverse == '\0')
			break;
		traverse++;
		len = len + _switch(*traverse, arg);
	}
	va_end(arg);
	return (len);
}
