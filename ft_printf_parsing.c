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

const char *flag_parse(const char *input, bool *flags)
{
	int i;

	i = 0;
	while (input[i] == '0' || input[i] == '#' || input[i] == '-' ||
			input[i] == '+' || input[i] == ' ')
	{
		if (add_flag(input[i], flags) == 1)
			return (NULL);
		i++;
	}
	return (input + i);
}

int len_modify(const char **input)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (*input[i] == 'h')
		{
			i = 1;
			if (*input[i + 1] == 'h')
				i = 2;
		}
		else if (*input[i] == 'l')
		{
			i = 3;
			if (*input[i + 2] == 'l')
				i = 4;
		}
	}
	*input = *input + i;
	return (i);
}

char ft_convr_parse(const char **input)
{
	char conversions[9] = "cspdiuxX";
	int i;

	i = 0;
	while (i < 8)
	{
		if (**input == conversions[i])
			return (**input);

		i++;
	}
	return (0);
}

int ft_printf_parse(const char **input, int precision, bool *flags, int len_modif)
{
	int i;
	int fld_wdt;

	i = 1;
	if (**input + 1 == '%')
		write(1, "%", 1);
	if ((*input = flag_parse(*input + 1, flags)))
		return (0);
	fld_wdt = ft_atoi(input);
	while (*input[i] >= 48 && *input[i] <= 57)
		*input++;
	precision = ft_atoi(input + 1);
	while (*input[i] >= 48 && *input[i] <= 57)
		*input++;
	i += len_modify(input);
	return (ft_convr_parse(input));
}

int main(int argc, char **argv)
{
	(void)argc;
	int i;
	bool flags[5];

	for(i = 0; i < 5; i++)
		flags[i] = 0;
	if (flag_parse(argv[1], flags) == NULL)
		return (1);
	for(i = 0; i < 5; i++)
		printf("flags[%d]:  %d\n", i, flags[i]);
	return(0);
}
