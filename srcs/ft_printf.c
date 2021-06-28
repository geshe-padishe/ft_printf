/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:07:53 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/28 05:32:19 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	draw_field(t_conv whoopty, int nb_digits, int options_length)
{
	int	precision;

	precision = whoopty.precision;
	if (whoopty.conversion == 0)
		precision = 1;
	if (whoopty.conversion == 'c')
		precision = 1;
	if (whoopty.conversion == 's')
		precision = ft_small_nb(precision, (int)ft_strlen(whoopty.string));
	if (whoopty.conversion == 'p' && whoopty.ptr == 0
		&& precision == 0 && whoopty.fld_wdt != 0)
		whoopty.fld_wdt++;
	while (whoopty.fld_wdt > precision + options_length
		&& whoopty.fld_wdt > nb_digits + options_length)
	{
		if (whoopty.flags[1] == 1 && (precision < 0
				|| whoopty.conversion == 0 || whoopty.conversion == 's'))
			charput("0", 1, 0);
		else
			charput(" ", 1, 0);
		whoopty.fld_wdt--;
	}
}

void	conv_bridge2(t_conv whoopty)
{
	if (whoopty.conversion == 's')
	{
		if (whoopty.flags[2] == 0)
			draw_field(whoopty, -1, 0);
		charput(whoopty.string,
			ft_small_nb(ft_strlen(whoopty.string), whoopty.precision), 0);
		if (whoopty.flags[2] == 1)
			draw_field(whoopty, -1, 0);
	}
	else if (whoopty.conversion == 'c')
	{
		if (whoopty.flags[2] == 0)
			draw_field(whoopty, -1, 0);
		charput(&whoopty.character, 1, 0);
		if (whoopty.flags[2] == 1)
			draw_field(whoopty, -1, 0);
	}
}

void	conv_bridge(t_conv whoopty, char c)
{
	if (whoopty.conversion == 0 && c)
		draw_field(whoopty, 0, 0);
	else if (whoopty.conversion == 'd' || whoopty.conversion == 'i')
		print_nb(whoopty.lnglng, 10, whoopty);
	else if (whoopty.conversion == 'u')
		print_nb(whoopty.un_lnglng, 10, whoopty);
	else if (whoopty.conversion == 'x')
		print_nb(whoopty.un_lnglng, 16, whoopty);
	else if (whoopty.conversion == 'X')
		print_nb(whoopty.un_lnglng, -16, whoopty);
	else if (whoopty.conversion == 'o')
		print_nb(whoopty.un_lnglng, 8, whoopty);
	else if (whoopty.conversion == 'p')
	{
		whoopty.flags[0] = 1;
		print_nb(1, 16, whoopty);
	}
	conv_bridge2(whoopty);
}

int	converter(const char *input, t_conv *whoopty, int i, va_list *ap)
{
	i += ft_printf_parse(whoopty, input + i, ap);
	if (whoopty->fld_wdt < 0)
	{
		whoopty->fld_wdt *= -1;
		whoopty->flags[2] = 1;
	}
	if (whoopty->flags[2] == 1)
		whoopty->flags[1] = 0;
	if (whoopty->flags[4] == 1)
		whoopty->flags[3] = 0;
	*whoopty = def_type(*whoopty, ap);
	if (input[i] && whoopty->conversion == 0 && whoopty->flags[2] == 1)
	{
		i++;
		charput((char *)&input[i - 1], 1, 0);
		conv_bridge(*whoopty, input[i - 1]);
	}
	else
		conv_bridge(*whoopty, input[i]);
	if (input[i] == '%' && whoopty->conversion == 0 && whoopty->flags[2] == 0)
	{
		i++;
		charput((char *)&input[i - 1], 1, 0);
	}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			ap;
	int				i;
	t_conv			whoopty;

	i = 0;
	va_start(ap, input);
	charput(NULL, 0, 1);
	while (input && input[i])
	{
		ft_bzero(&whoopty, sizeof(whoopty));
		whoopty.precision = -1;
		if (input[i] != '%')
			charput((char *)&input[i++], 1, 0);
		else if (input[i + 1] == '%')
		{
			charput("%", 1, 0);
			i += 2;
		}
		else if (input[i + 1] == 0)
			return (charput(NULL, 0, 0));
		else
			i = converter(input, &whoopty, i + 1, &ap);
	}
	va_end(ap);
	return (charput(NULL, 0, 0));
}
