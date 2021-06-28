/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotikcho <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:37:17 by nikotikch         #+#    #+#             */
/*   Updated: 2021/06/27 18:03:32 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	charput(char *character, int nb_char, bool reset)
{
	static int	ret = 0;

	if (reset == 1)
		ret = 0;
	if (nb_char > 0)
	{
		ret += nb_char;
		write(1, character, nb_char);
	}
	return (ret);
}

t_conv	def_type(t_conv whoopty, va_list *ap)
{
	if (whoopty.conversion == 'd' || whoopty.conversion == 'i')
		whoopty.lnglng = va_arg(*ap, int);
	else if (whoopty.conversion == 's')
	{
		whoopty.string = va_arg(*ap, char *);
		if (whoopty.string == NULL)
			whoopty.string = "(null)";
	}
	else if (whoopty.conversion == 'c')
		whoopty.character = (char)va_arg(*ap, int);
	else if (whoopty.conversion == 'x' || whoopty.conversion == 'X'
		|| whoopty.conversion == 'o' || whoopty.conversion == 'u')
		whoopty.un_lnglng = va_arg(*ap, unsigned int);
	else if (whoopty.conversion == 'p')
		whoopty.ptr = (unsigned long)va_arg(*ap, void *);
	return (whoopty);
}
