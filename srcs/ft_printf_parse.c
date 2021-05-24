/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:48 by ngenadie          #+#    #+#             */
/*   Updated: 2021/05/24 18:27:38 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
