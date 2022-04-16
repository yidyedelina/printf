#include "main.h"
#include "stdio.h"
/**
 * _switch - custom switch function;
 * @traverse: a char
 * @arg: an argument
 * Return: a length
 */
int _switch(char traverse, va_list arg)
{
	int len = 0;

	switch (traverse)
		{
			case 'c':
				len = len + _putc(va_arg(arg, int));
				break;
			case 's':
				len = len + _putstr(va_arg(arg, char *));
				break;
			case '%':
				putchar('%');
				len++;
				break;
			case 'd':
				len = len + printnum(traverse, va_arg(arg, int));
				break;
			case 'i':
				len = len + printnum(traverse, va_arg(arg, int));
				break;
			case 'b':
				len = len + printnum(traverse, va_arg(arg, int));
				break;
			case 'u':
				len = len + printnum(traverse, va_arg(arg, int));
				break;
			case 'o':
				len = len + printnum(traverse, va_arg(arg, int));
				break;
			case 'x':
				len = len + printnum(traverse, va_arg(arg, int));
				break;
			case 'X':
				len = len + printnum(traverse, va_arg(arg, int));
				break;
			case 'S':
				len = len + _putStr(va_arg(arg,char *));
				break;
			default:
				putchar('%');
				putchar(traverse);
				len = len + 2;
				break;
		}
		return (len);
}
