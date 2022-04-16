#include "main.h"
#include "stdio.h"
#include "string.h"
#include <math.h>
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
/**
 * print_p - print the memory address
 * n: AN ADDREESS
 * Return: int
 */
int print_p(unsigned long n)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long m;
	char *str = "(nil)";

	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			putchar(str[i]);
			count++;
		}
		return (count);
	}
	putchar('0');
	putchar('x');
	count = 2;
	m = pow(16, 15); /* 16 ^ 15 */
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				putchar('0' + a[i]);
			else
				putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
