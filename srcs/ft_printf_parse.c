/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:48 by ngenadie          #+#    #+#             */
/*   Updated: 2021/05/24 20:09:28 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void add_flag(char flag, bool *flags)
{
	if (flag == '#')
		flags[0] = 1;
	if (flag == '0')
		flags[1] = 1;
	if (flag == '-')
		flags[2] = 1;
	if (flag == '+')
		flags[3] = 1;
	if (flag == ' ')
		flags[4] = 1;
}

int flag_parse(const char *input, bool *flags)
{
	int i;

	i = 0;
	while (input[i] == '0' || input[i] == '#' || input[i] == '-' ||
			input[i] == '+' || input[i] == ' ')
	{
		add_flag(input[i], flags);
		i++;
	}
	return (i);
}

int ft_printf_parse(conv *whoopty, const char *input, va_list *ap)
{
	int i;
	int j;

	i = 0;
	while (input[i])
	{
		j = 0;
		i += flag_parse(input, whoopty->flags);
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
			else
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
