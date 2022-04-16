#include "stdio.h"
#include "stdarg.h"
/**
 * printstr - print character
 * 
 * @param s: the string character
 * @return int 
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
	return len;
}
/**
 * @brief the function that converts strings
 * 
 * @param num 
 * @param base 
 * @return char* 
 */
char *convert(unsigned int num,int base)
{
	static char Representation[] = "0123456789ABCDEF";
	static char buffer[65];
	char *ptr;

	ptr = &buffer[64];
	*ptr = '\0';
	do
	{
		*--ptr =  Representation[num % base];
		num /= base;
	}while(num != 0);
	return (ptr);
}
/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int _printf(const char *format, ...)
{
	const char *traverse;
	int len = 0;
	int i;
	char *s;
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
			case 'd':
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = i * (-1);
					putchar('-');
					len++;
				}
				len = len + printstr(convert(i, 10));
				break;
			case 'i':
				i = va_arg(arg, int);
				if (i < 0)
				{
					i = i * (-1);
					putchar('-');
					len++;
				}
				len = len + printstr(convert(i, 10));
				break;
			case 'b':
				i = va_arg(arg, int);
				len = len + printstr(convert(i, 2));
				break;
			case 'o':
				i = va_arg(arg, int);
				len = len + printstr(convert(i, 8));
				break;
			case 'x':
				i = va_arg(arg, int);
				len = len + printstr(convert(i, 16));
				break;
			case 'X':
				i = va_arg(arg, int);
				len = len + printstr(convert(i, 16));
				break;
			case 'u':
				i = va_arg(arg, int);
				if(i < 0)
				{
					i = -i;
				}
				len = len + printstr(convert(i, 10));
				break;
			case 'S':
				s = va_arg(arg, char*);
				while (*s != '\0')
				{
					if (*s > 0 && *s < 32)
					{
						putchar('\\');
						putchar('x');
						len = len + printstr(convert(*s, 16));
						len + 2;
					}
					putchar(*s);
					s++;
				}
				break;
			case 'p':
				s = va_arg(arg, int*);
				printstr(s);
		}
	}
	va_end(arg);
	return len;
}
