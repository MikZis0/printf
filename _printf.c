#include "main.h"

int _putchar(char c) {
    return (write(1, &c, 1));
}

int _printf(const char *format, ...);{

    va_list args;
    int charsPrinted = 0;
    va_start(args, format);

    // printf('Hello world, %c %s"", 'a', "string")

    while(*format != '/0') {
            if (*format == '%') {
                    // increment the pointer first
                    format++;
                    switch(*format) {
                    case 'c':
                        {
                             int c = va_arg(args, int);
                            _putchar(c);
                            charsPrinted++;
                            format++;
                        }

                        break;
                    case 's':
                        {
                            char *str = va_arg(args, char*);
                            while(*str != "\0") {
                                charsPrinted++;
                                _putchar(*str);
                                str++;
                            }
                            format++;
                        }

                        break;
                    default:
                        _putchar(*format);
                        charsPrinted++;
                    }

            }else {
                charsPrinted++;
                // print char to std out
                _putchar(*format); // What if this errors out
                // increment pointer
                format++;
            }
    }
    va_end(args);

    return charsPrinted;
}
