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
	int len;

	if (s == NULL)
		s = "(null)";
	len = len + printstr(s);
}
