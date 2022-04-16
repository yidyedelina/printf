#include "main.h"
#include "stdio.h"
/**
 * _putc - a character specifier
 * @c: a character
 * Return: a string
 */

int _putc(char c)
{
	putchar(c);
	return (1);
}
/**
 * _putstr - print strings
 * @s: a string
 * Return: integer always
 */
int _putstr(char *s)
{
	int len = 0;

	if (s == NULL)
		s = "(null)";
	len = len + printstr(s);
	return (len);
}
int _putStr(char *s)
{
	int len = 0;
	while (*s != '\0')
	{
		if (*s > 0 && *s < 32)
		{
			putchar('\\');
			putchar('x');
			len = len + printstr(convert(*s, 16));
			len = len + 2;
		}
		else
		{
			putchar(*s);
			len++;
		}
		s++;
	}
	return (len);
}
