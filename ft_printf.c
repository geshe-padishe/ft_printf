#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
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

char *flag_parse(const char *input, bool *flags)
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

int field_width(const char *input)
{
	return (ft_atoi(input));
}

int precision(const char *input)
{
	return (ft_atoi(input));
}

int length_modifier(const char *input)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (input[i] == 'h')
		{
			i = 1;
			if (input[i + 1] == 'h')
				i = 2;
		}
		else if (input[i] == 'l')
		{
			i = 3;
			if (input[i + 2] == 'l')
				i = 4;
		}
	}
	return (i);
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
