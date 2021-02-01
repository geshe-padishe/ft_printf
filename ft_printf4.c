#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

void print_char(char c)
{
	write(1, &c, 1);
}

void print_simple(char *flags, char conversion, int precision)
{
	if (conversion == 's')
		print_str(str, precision);
	if (conversion == 'c')
		print_char(c);
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
