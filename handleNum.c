#include "main.h"
#include "stdio.h"
#include "string.h"
/**
 * printdec - print decimal number
 * @n: an integer
 * Return: nteger;
 */
int printdec(int n)
{
	int len = 0;

	if (n < 0)
	{
		n = n * (-1);
		putchar('-');
		len++;
	}
	len = len + printstr(convert(n, 10));
	return (len);
}
/**
 * convert2 - change any lower case letter to uppercase letter
 * @num: a number
 * @base: base;
 * Return: return a char pointer
 */
char *convert2(unsigned int num, int base)
{
	static const char Representation[] = "0123456789abcdef";
	static char buffer[65];
	char *ptr;

	ptr = &buffer[64];
	*ptr = '\0';
	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}

/**
 * printNum - print numbers
 * @traverse: a specifier
 * @n: a number
 * Return: the length of the number printed
 */
int printnum(char traverse, int n)
{
	int len = 0;

	switch (traverse)
	{
	case 'd':
		return (printdec(n));
	case 'i':
		return (printdec(n));
	case 'b':
		len = len + printstr(convert(n, 2));
		return (len);
	case 'o':
		len = len + printstr(convert(n, 8));
		return (len);
	case 'X':
		len = len + printstr(convert(n, 16));
		return (len);
	case 'u':
		len = len + printstr(convert(n, 10));
		return (len);
	case 'x':
		len = len + printstr(convert2(n, 16));
		return (len);
	}
	return (0);
}
