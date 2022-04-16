#include "main.h"
#include "string.h"
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
	else if (*s == '\0')
		return (-1);
	len = len + printstr(s);
	return (len);
}
/**
 * _putStr - print printable string
 * @s: a string
 * Return: always length;
 */
int _putStr(char *s)
{
	int len = 0;
	char *p;

	if (s == NULL)
		s = "(null)";
	else if (*s == '\0')
		return (-1);
	while (*s != '\0')
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			putchar('\\');
			putchar('x');
			p = convert(*s, 16);
			if (*s < 16)
			{
				putchar('0');
				len++;
			}
			len = len + printstr(p);
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
