#include "ft_printf.h"

ft_printf_parse(conv *whoopty, char *input)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (input[i])
	{
		while ("sciduoxX"[j])
		{
			if (input[i] == "sciduoxX"[j])
			{
				whoopty->conversion = "sciduoxX"[j];
				return (0);
			}
			j++;
		}
		if (input[i] == 'l' || input[i] == 'h')
			(ft_len_mod(input[i]), &whoopty->len_mod);
	}
}
