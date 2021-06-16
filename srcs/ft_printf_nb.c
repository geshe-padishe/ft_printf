/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:40:34 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/16 17:38:06 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int ft_small_nb(int nb1, int nb2)
{
	if (nb1 < 0)
		return (nb2);
	if (nb2 < 0)
		return (nb1);
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

int nb_digites(long long nb, int base)
{
	int nb_digits;

	nb_digits = 1;
	while ((nb = nb / base) > 0)
		nb_digits++;
	return (nb_digits);
}

int nb_undigites(unsigned long nb)
{
	int nb_digits;

	nb_digits = 1;
	while ((nb = nb / 16) > 0)
		nb_digits++;
	return (nb_digits);
}

long long abs_value(long long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void write_digits(long long nb, int base)
{
	int abs_base;

	abs_base = base;
	if (base < 0)
		abs_base = -base;
	if (nb >= abs_base)
		write_digits(nb / abs_base, base);
	if (base == 16)
		charput(&"0123456789abcdef"[nb % 16], 1, 0);
	else if (base == -16)
		charput(&"0123456789ABCDEF"[nb % 16], 1, 0);
	else if (base == 8)
		charput(&"01234567"[nb % 8], 1, 0);
	else
	   charput(&"0123456789"[nb % 10], 1, 0);
}

void write_undigits(unsigned long nb)
{
	if (nb >= 16)
		write_undigits(nb / 16);
	charput(&"0123456789abcdef"[nb % 16], 1, 0);
}

void print_nb_options(bool *flags, int base, long long nb)
{
	if (base == 16)
		if (flags[0] == 1)
			charput("0x", 2, 0);
	if (base == -16)
		if (flags[0] == 1)
			charput("0X", 2, 0);
	if (base == 8 && flags[0] == 1)
		charput("0", 1, 0);
	if (base == 10)
	{
		if (flags[4] == 1)
			if (nb > 0)
				charput(" ", 1, 0);
		if (flags[3] == 1)
			if (nb >= 0)
				charput("+", 1, 0);
	}
}

int options_length(bool *flags, int base, long long nb)
{
	if (base == 16)
		if (flags[0] == 1)
			return (2);
	if (base == -16)
		if (flags[0] == 1)
			return (2);
	if (base == 10)
	{
		if (nb < 0)
			return (1);
		if (flags[4] == 1)
		{
			if (nb > 0)
				return (1);
			else
				return (0);
		}
		if (flags[3] == 1)
		{
			if (nb > 0)
				return (1);
			else if (nb < 0)
				return (1);
		}
	}
	return (0);
}

void draw_field(conv whoopty, int nb_digits, int options_length)
{
	if (whoopty.conversion == 0)
		whoopty.precision = 1;
	if (whoopty.conversion == 'c')
		whoopty.precision = 1;
	if (whoopty.conversion == 's')
		whoopty.precision = ft_small_nb(whoopty.precision, (int)ft_strlen(whoopty.string));
	if (whoopty.conversion == 'p' && whoopty.ptr == 0 && whoopty.precision == 0 && whoopty.fld_wdt != 0)
		whoopty.fld_wdt++;
	while (whoopty.fld_wdt > whoopty.precision + options_length &&
			whoopty.fld_wdt > nb_digits + options_length)
	{
		if (whoopty.flags[1] == 1 && (whoopty.precision < 0 || whoopty.conversion == 0 || whoopty.conversion == 's'))
			charput("0", 1, 0);
		else
			charput(" ", 1, 0);
		whoopty.fld_wdt--;
	}
}
//BEFORE PRINT_NB PUT PRECISION TO NB_DIGITS+1
void print_nb(long long nb, int base, conv whoopty)
{
	long long nb_s;
	int nb_digits;
	int abs_base;
	int precision;

	precision = whoopty.precision;
	abs_base = abs_value(base);
	nb_s = abs_value(nb);
	if (whoopty.conversion != 'p')
		nb_digits = nb_digites(nb_s, abs_base);
	else
		nb_digits = nb_undigites(whoopty.ptr);
	if (nb < 0 && whoopty.precision < 0 && whoopty.flags[1] == 1 && whoopty.conversion != 'p')
		charput("-", 1, 0);
	if (nb == 0 && whoopty.precision == 0)
		whoopty.fld_wdt++;
	if (whoopty.flags[2] == 0)
		draw_field(whoopty, nb_digits, options_length(whoopty.flags, base, nb));
	print_nb_options(whoopty.flags, base, nb);
	if (nb < 0 && (whoopty.flags[1] == 0 || whoopty.precision >= 0))
		charput("-", 1, 0);
	while (precision-- > nb_digits)
		charput("0", 1, 0);
	nb_s = abs_value(nb);
	if ((nb != 0 || whoopty.precision != 0) && whoopty.conversion != 'p')
		write_digits(nb_s, base);
	else if (whoopty.conversion == 'p' && (whoopty.ptr != 0 || whoopty.precision != 0))
		write_undigits(whoopty.ptr);
	if (whoopty.flags[2] == 1)
		draw_field(whoopty, nb_digits, options_length(whoopty.flags, base, nb));
}

//int main(int argc, char **argv)
//{
//	long long nb;
//	int base;
//
//	(void)argc;
//	nb = (long long)atoi(argv[1]);
//	base = atoi(argv[2]);
//	printf("nb = %lld\n", nb);
//	printf("base = %d\n", base);
//	printf("\n%020.5lld\n", nb);
//}
