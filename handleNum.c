#include "main.h"
#include "stdio.h"
/**
 * printdec - print decimal number
 * @n: an integer
 * Return integer;
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
    }
    return (0);
}
