/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:28:06 by ngenadie          #+#    #+#             */
/*   Updated: 2021/05/14 17:45:52 by ngenadie         ###   ########.fr       */
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

typedef struct	conv
{
	int precision;
	int fld_wdt;
	char conversion;
	bool flags[5];
	char len_modif;
	long long lnglng;
	unsigned long long un_lnglng;
	char *string;
}				conv;

bool add_flag(char flag, bool *flags);
int flag_parse(const char *input, bool *flags);
int len_modif(const char *input, char *len_mod);
char ft_convr_parse(const char *input, conv *whoopty);
int ft_printf_parse(const char *input, conv *whoopty);
int nb_digites(long long nb, int base);
long long abs_value(long long nb);
void write_digits(long long nb, int base);
void print_nb_options(bool *flags, int base, long long nb);
int options_length(bool *flags, int base, long long nb);
void print_nb(long long nb, int base, conv whoopty);
void print_str(char *str, int precision);
void ft_putchar(unsigned char c);
conv def_type(conv whoopty, va_list *ap);
void print_sc(bool *flags, char conversion, int precision, va_list ap);
int ft_printf(const char *input, ...);

#endif
