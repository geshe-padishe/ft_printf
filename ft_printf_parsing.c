#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>

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

int len_modif(const char **input, int *len_mod)
{
	int i;

	i = *len_mod;
	while (*input[i] < 2)
	{
		if (*input[i] == 'h')
		{
			*len_mod = 1;
			if (*input[i + 1] == 'h')
			{
				*len_mod = 2;
				return (2);
			}
			return (1);
		}
		else if (*input[i] == 'l')
		{
			*len_mod = 3;
			if (*input[i + 2] == 'l')
			{
				*len_mod = 4;
				return (2);
			}
			return (1);
		}
	}
	return (0);
}

char ft_convr_parse(const char **input, char conv)
{
	char conversions[9] = "cspdiuxX";
	int i;

	i = 0;
	while (i < 8)
	{
		if (**input == conversions[i])
			return (1);
		i++;
	}
	return (0);
}

int ft_printf_parse(const char **input, int *precision, bool *flags, int *len_mod, int *fld_wdt)
{
	int i;

	i = 0;
	if (input[0][1] == '%')
		write(1, "%", 1); return (1);
	if ((i = flag_parse(*input + 1, flags)) == -1)
		return (0);
	*fld_wdt = ft_atoi(*input[i]);
	while (*input[i] >= 48 && *input[i] <= 57)
		input++;
	if (*input[i++] == '.')
		*precision = ft_atoi(input + i);
	while (*input[i] >= 48 && *input[i] <= 57)
		input++;
	i += len_modif(input, len_mod);
	if (ft_convr_parse(&input[i]);
	return (i);
}

int main(int argc, char **argv)
{
	(void)argc;
	int i;
	bool flags[5];

	for(i = 0; i < 5; i++)
		flags[i] = 0;
	for(i = 0; i < 5; i++)
		printf("flags[%d]:  %d\n", i, flags[i]);
	return(0);
}
