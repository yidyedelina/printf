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
int _putstr(char *str)
{
	int count;

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		putchar(str[count]);
	}
	return (count);
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
/**
 * print_rev - print a string in a reverse order
 * @s: a string variable
 * Return: void
 */
int print_r(char *str)
{
	int i, count = 0;

	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		putchar(str[i]);
		count++;
	}
	return (count);
}

/**
 * print_R - prints a string in rot13
 * @R: string to print
 *
 * Return: number of chars printed
 */
int print_R(char *str)
{
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		str = "(ahyy)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				putchar(out[j]);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			putchar(str[i]);
			count++;
		}
	}
	return (count);
}
