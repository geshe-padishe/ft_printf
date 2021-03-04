#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

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

void print_char(unsigned char c)
{
	write(1, &c, 1);
}

void print_sc(char *flags, char conversion, int precision)
{
	if (conversion == 's')
		print_str(str, precision);
	if (conversion == 'c')
		print_char(c);
}

int ft_printf(const char *input, ...)
{
	va_list ap;
	int i;
	bool flags[5];

	i = 0;
	va_start(ap, input);
	while (input[i])
	{
		if (input[i] != '%')
			write(1, &input[i], 1);
		else
			i += ft_printf_parse(&input, &precision, flags, &len_mod, &fld_wdt);
		i++;
	}
	va_end(ap);
}

int main(int argc, char **argv)
{
	int precision;

	(void)argc;
	precision = atoi(argv[2]);
	dprintf(1, "str: ");
	print_str(argv[1], precision);
	dprintf(1, "\nchar: ");
	print_char(argv[1][0]);
	printf("\nstring with 0 precision: ");
	printf("%.s\n", "ggsdafew");
}
