#include "main.h"

int _printf(const char *format, ...)
{
	int charsPrinted = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						int c = va_arg(args, int);
						putchar(c);
						charsPrinted++;
					}
					break;
				case 's':
					{
						char *str = va_arg(args, char*);
						while (*str != '\0')
						{
							putchar(*str);
							str++;
							charsPrinted++;
						}
					}
					break;
				case '%':
					{
						int p = va_arg(args, int);
						putchar(p);
						charsPrinted++;
					}
					break;
			}
		}
		else
		{
			putchar(*format);
			charsPrinted++;
		}
		format++;
	}
	va_end(args);
	return (charsPrinted);
}
