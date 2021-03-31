#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "ft_printf.h"

void print_str(char *str, int precision)
{
	int i;

	i = 0;
	while (str[i] && i < precision)
	{
		write(1, str + i, 1);
		i++;
	}
}

void ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void print_sc(char *flags, char conversion, int precision, va_list ap)
{
	if (conversion == 's')
		print_str(str, precision);
	if (conversion == 'c')
		ft_putchar(c);
}

type def_type(conv whoopty, va_list *ap)
{
	type argument;
	if (whoopty.conversion == 'd' || whoopty.conversion == 'i' || whoopty.conversion == 'c')
	{
		if (whoopty.len_modif == 'l' || whoopty.len_modif == 'L')
			argument.lnglng = va_arg(*ap, long long);
		argument.lnglng = va_arg(*ap, int);
	}
	else if (whoopty.conversion == 's')
		argument.string = va_arg(*ap, char*);
	else
		argument.un_lnglng = va_arg(*ap, unsigned long long);
	return (argument);
}

int ft_printf(const char *input, ...)
{
	va_list ap;
	int i;
	conv whoopty;

	i = 0;
	va_start(ap, input);
	while (input[i])
	{
		if (input[i] != '%')
			write(1, &input[i], 1);
		else
		{
			i += ft_printf_parse(&input, &whoopty);
			if (i == 0)
				return (-1);
		}
		i++;
	}
	va_end(ap);
}

void test_fct(int arg_ct, ...)
{
	va_list ap;
	type argument;

	va_start(ap, arg_ct);
	argument.lnglng = va_arg(ap, int);
	printf("arg.lnglng = %lld\n", argument.lnglng);
	argument.lnglng = va_arg(ap, int);
	printf("arg.lnglng = %lld\n", argument.lnglng);
	argument.lnglng = va_arg(ap, long);
	printf("arg.lnglng = %lld\n", argument.lnglng);
	va_end(ap);
}

int main(int argc, char **argv)
{
	int integer;
	long long longteger;
	short shorteger;
	conv conversion;
	int conv_len = 0;

	conv_len = sizeof(conversion);
	bzero(&conversion, conv_len);
	shorteger = 32332;
	longteger = 321432144324231;
	integer = 1232132231;
	(void)argc;
	conversion.precision = atoi(argv[2]);
	dprintf(1, "str: ");
	print_str(argv[1], conversion.precision);
	dprintf(1, "\nchar: ");
	ft_putchar(argv[1][0]);
	printf("\nstring with 0 precision: ");
	printf("%.s\n", "ggsdafew");

	test_fct(1, shorteger, integer, longteger);
	printf("short: %ld, int: %ld, long: %ld, long long: %ld\n", sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
}
