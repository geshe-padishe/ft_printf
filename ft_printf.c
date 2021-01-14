#include <stdio.h>
#include <string.h>
#include <ctype.h>

int fill_flag_chart(uint64_t x, const char *input, char **flag_chart)
{
	uint64_t i;

	i = 0;
	if (input[x + i] == '#')
		flag_chart[1][i++] = 1;
	if (input[x + i] == '0')
		flag_chart[1][i++] = 1;
	if (input[x + i] == '-')
		flag_chart[1][i++] = 1;
	if (input[x + i] == ' ')
		flag_chart[1][i++] = 1;
	if (input[x + i] == '+')
		flag_chart[1][i++] = 1;
	if (i > 0)
		return (1);
	return (0);
}

int fill_lengths(uint64_t x, const char *input, uint64_t *lengths)
{
	uint64_t i;

	i = 0;
	if (input[x + i] >= '0' && input[x + i] <= '9')
		width = ft_atoi(input, x);
	if (input[x + i] == '.')
	{
		if (input [x + i + 1] && input[x + i + 1] >= '0' && input[x + i + 1] <= '9')
			precision = ft_atoi(input, x + i + 1)
		else
			return (-1);
	}
	return (1);
}

int fill_length_modifiers(uint64_t x, const char *input)
{
	int length;

	length = 0;
	if (input[x] == 'l')
	{
		if (input[x + i + 1] == 'l')
			length = 2;
		else
			length = 1;
	}
	if (input[x + i] == 'h')
	{
		if (input[x + i + 1] == 'h')
			length = 4;
		else
			length = 3;
	}
	return (length);
}

int ft_printf(const char *input, ...)
{
	uint64_t i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != '%')
			conversions = conversion(); //finish....
		i++;
	}
}
