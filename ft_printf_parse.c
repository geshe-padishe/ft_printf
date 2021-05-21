#include "ft_printf.h"

char ft_len_mod(char new_len_mod char *old_len_mod)
{
	if (new_len_mod == 'h')
}
ft_printf_parse(conv *whoopty, char *input)
{
	int i;
	int j;

	i = 0;
	while (input[i])
	{
		j = 0;
		if (input[i] == 'l' || input[i] == 'h')
			(ft_len_mod(input[i]), &whoopty->len_mod);
		if (input[i] >= 48 && input[i] <= 57)
			whoopty->fld_wdt = ft_atoi(&input[i]);
		while (input[i] >= 48 && input[i] <= 57)
			i++;
		if (input[i] == '.')
		{
			i++;
			whoopty->precision = ft_atoi(&input[i]);
			while (input[i] >= 48 && input[i] <= 57)
				i++;
		}
		while (j < 8)
		{
			if (input[i] == "sciduoxX"[j])
			{
				whoopty->conversion = "sciduoxX"[j];
				return (i);
			}
			j++;
		}
	}
	return (-1);
}
