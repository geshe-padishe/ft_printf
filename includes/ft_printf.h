/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:28:06 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/13 15:18:50 by ngenadie         ###   ########.fr       */
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
	long long lnglng;
	unsigned int un_lnglng;
	char *string;
	char character;
	unsigned long ptr;
}				conv;

void draw_field(conv whoopty, int nb_digits, int options_length);
void add_flag(char flag, bool *flags);
int flag_parse(const char *input, bool *flags);
int len_modif(const char *input, char *len_mod);
char ft_convr_parse(const char *input, conv *whoopty);
int nb_digites(long long nb, int base);
int ft_printf_parse(conv *whoopty, const char *input, va_list *ap);
long long abs_value(long long nb);
void write_digits(long long nb, int base);
void print_nb_options(bool *flags, int base, long long nb);
int options_length(bool *flags, int base, long long nb);
void print_nb(long long nb, int base, conv whoopty);
void print_str(conv whoopty);
int ft_putchar(conv whoopty);
conv def_type(conv whoopty, va_list *ap);
void print_sc(bool *flags, char conversion, int precision, va_list ap);
int ft_printf(const char *input, ...);
void flag_peacemaker(bool *flags);
void prec_wdt(const char *input, conv *whoopty, va_list *ap, int *i);
int charput(char *character, int nb_char, bool reset);
int ft_small_nb(int nb1, int nb2);
void write_undigits(unsigned long nb);
int nb_undigites(unsigned long nb);

#endif
