/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:28:06 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/24 18:47:21 by nikotikch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "libft.h"

typedef struct	s_conv
{
	int				precision;
	int				fld_wdt;
	char			conversion;
	bool			flags[5];
	long long		lnglng;
	unsigned int	un_lnglng;
	char			*string;
	char			character;
	unsigned long	ptr;
}				s_conv;

void	draw_field(s_conv whoopty, int nb_digits, int options_length);
int	flag_parse(const char *input, bool *flags);
int	len_modif(const char *input, char *len_mod);
char	ft_convr_parse(const char *input, s_conv *whoopty);
int	nb_digites(long long nb, int base);
int	ft_printf_parse(s_conv *whoopty, const char *input, va_list *ap);
long long	abs_value(long long nb);
void	write_digits(long long nb, int base);
void	print_nb_options(bool *flags, int base, long long nb);
int	options_length(bool *flags, int base, long long nb);
void	print_nb(long long nb, int base, s_conv whoopty);
void	print_str(s_conv whoopty);
int	ft_putchar(s_conv whoopty);
s_conv	def_type(s_conv whoopty, va_list *ap);
void	print_sc(bool *flags, char conversion, int precision, va_list ap);
int	ft_printf(const char *input, ...);
void	flag_peacemaker(bool *flags);
void	prec_wdt(const char *input, s_conv *whoopty, va_list *ap, int *i);
int	charput(char *character, int nb_char, bool reset);
int	ft_small_nb(int nb1, int nb2);
void	write_undigits(unsigned long nb);
int	nb_undigites(unsigned long nb);
void	conv_bridge2(s_conv whoopty);
int	converter(const char *input, s_conv *whoopty, int i, va_list *ap);
int	ft_printf_parse2(s_conv *whoopty, const char *input, va_list *ap, int i);

#endif
