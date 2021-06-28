/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:48 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/28 05:39:48 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_parse(const char *input, bool *flags)
{
	int	i;

	i = 0;
	while (input[i] == '0' || input[i] == '#' || input[i] == '-'
		|| input[i] == '+' || input[i] == ' ')
	{
		if (input[i] == '#')
			flags[0] = 1;
		if (input[i] == '0')
			flags[1] = 1;
		if (input[i] == '-')
			flags[2] = 1;
		if (input[i] == '+')
			flags[3] = 1;
		if (input[i] == ' ')
			flags[4] = 1;
		i++;
	}
	return (i);
}

int	conv_parse(const char *input, t_conv *whoopty)
{
	int	j;

	j = 0;
	while (j < 9)
	{
		if (*input == "scpiduoxX"[j])
		{
			whoopty->conversion = "scpiduoxX"[j];
			return (1);
		}
		j++;
	}
	return (0);
}

int	ft_parse(t_conv *whoopty, const char *input, va_list *ap, int i)
{
	i++;
	if (input[i] == '*' && input[i++] == '*')
		whoopty->precision = va_arg(*ap, int);
	else if (input[i] >= 48 && input[i] <= 57)
		whoopty->precision = ft_atoi(&input[i]);
	else
		whoopty->precision = 0;
	while (input[i] >= 48 && input[i] <= 57)
		i++;
	return (i);
}

int	ft_printf_parse(t_conv *whoopty, const char *input, va_list *ap)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (flag_parse(input + i, whoopty->flags) > 0)
			i += flag_parse(input + i, whoopty->flags);
		else if (input[i] >= 48 && input[i] <= 57)
		{
			whoopty->fld_wdt = ft_atoi(&input[i]);
			while (input[i] >= 48 && input[i] <= 57)
				i++;
		}
		else if (input[i] == '*' && input[i++] == '*')
			whoopty->fld_wdt = va_arg(*ap, int);
		else if (input[i] == '.')
			i = ft_parse(whoopty, input, ap, i);
		else if (conv_parse(input + i, whoopty)
			&& conv_parse(input + i++, whoopty))
			return (i);
		else
			return (i);
	}
	return (i);
}
