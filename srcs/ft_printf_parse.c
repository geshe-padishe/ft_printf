#include "ft_printf.h"

int ft_printf_parse(conv *whoopty, const char *input, va_list *ap)
{
	int i;
	int j;

	i = 0;
	while (input[i])
	{
		j = 0;
		if (input[i] >= 48 && input[i] <= 57)
			whoopty->fld_wdt = ft_atoi(&input[i]);
		while (input[i] >= 48 && input[i] <= 57)
			i++;
		if (input[i] == '*' && (i = i + 1))
			whoopty->fld_wdt = va_arg(*ap, int);
		if (input[i] == '.')
		{
			i++;
			if (input[i] == '*' && (i = i + 1))
				whoopty->precision = va_arg(*ap, int);
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
		i++;
	}
	return (i);
}
