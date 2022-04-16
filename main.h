#ifndef _INCL_GUARD
#define _INCL_GUARD
#include <stdarg.h>
int _printf(const char *format, ...);
int printstr(char *s);
int _switch(char traverse, va_list  arg);
int _putc(char c);
int _putstr(char *s);
int printnum(char traverse, int n);
char *convert(unsigned int num, int base);

#endif


