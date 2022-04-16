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
	int i, len = 0;
	char *s;

	switch (traverse)
		{
			case 'c':
				i = va_arg(arg, int);
				putchar(i);
				len++;
				break;
			case 's':
				s = va_arg(arg, char *);
				if (s == NULL)
					s = "(null)";
				len = len + printstr(s);
				break;
			case '%':
				putchar('%');
				len++;
				break;
			default:
				putchar('%');
				putchar(traverse);
				len = len + 2;
				break;
		}
		return (len);
}
