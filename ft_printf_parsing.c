#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

bool add_flag(char flag, bool *flags)
{
	if (flag == '#')
		if (flags[0] != 1 && (flags[0] = 1))
			return (0);
	if (flag == '0')
		if (flags[1] != 1 && (flags[1] = 1))
			return (0);
	if (flag == '-')
		if (flags[2] != 1 && (flags[2] = 1))
			return (0);
	if (flag == '+')
		if (flags[3] != 1 && (flags[3] = 1))
			return (0);
	if (flag == ' ')
		if (flags[4] != 1 && (flags[4] = 1))
			return (0);
	return (1);
}

int flag_parse(const char *input, bool *flags)
{
	int i;

	i = 0;
	while (input[i] == '0' || input[i] == '#' || input[i] == '-' ||
			input[i] == '+' || input[i] == ' ')
	{
		if (add_flag(input[i], flags) == 1)
			return (-1);
		i++;
	}
	return (i);
}

int len_modif(const char *input, char *len_mod)
{
	int i;

	i = 0;
	if (input[0] == 'h')
	{
		*len_mod = 'h';
		if (input[1] == 'h')
		{
			*len_mod = 'H';
			return (2);
		}
		return (1);
	}
	else if (input[0] == 'l')
	{
		*len_mod = 'l';
		if (input[1] == 'l')
		{
			*len_mod = 'L';
			return (2);
		}
		return (1);
	}
	return (0);
}

char ft_convr_parse(const char *input, conv *whoopty)
{
	int i;
	char convs[9] = "diouxXcs";

	i = 0;
	while (i < 8)
	{
		if (*input == convs[i])
		{
			whoopty->conversion = *input;
			return (1);
		}
		i++;
	}
	return (0);
}

int ft_printf_parse(const char *input, conv *whoopty)
{
	int i;

	i = 1;
	if (input[1] == '%')
		write(1, "%", 1);
	if ((i += flag_parse(input + 1, whoopty->flags)) == -1)
		return (0);
	whoopty->fld_wdt = ft_atoi(&input[i]);
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	if (input[i] == '.')
	{
		i++;
		whoopty->precision = ft_atoi(input + i);
	}
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	i += len_modif(&input[i], &whoopty->len_modif);
	if (ft_convr_parse(&input[i], whoopty) == 0)
		return (0);
	return (i);
}

int print_conv(conv *whoopty)
{
	int i = 0;
	for(i = 0; i < 5; i++)
		printf("flags[%d]:  %d\n", i, whoopty->flags[i]);
	printf("field width: %i\n", whoopty->fld_wdt);
	printf("precision: %i\n", whoopty->precision);
	printf("length modif: %c\n", whoopty->len_modif);
	printf("conversion: %c\n", whoopty->conversion);
	return 0;
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	int i;
//	int ret;
//	conv whoopty;
//
//	bzero(&whoopty, sizeof(whoopty));
//
//	printf("input: %s\n", argv[1]);
//
//	if ((ret = ft_printf_parse(argv[1], &whoopty)) == 0)
//		return (1);
//	print_conv(&whoopty);
//	return (i);
//}
