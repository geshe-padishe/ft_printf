/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:07:53 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/13 13:37:37 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "ft_printf.h"

void print_conv(conv whoopty)
{
	int i = 0;
	dprintf(1, "\n--------------------------------------\n");
	for(i = 0; i < 5; i++)
		dprintf(1, "flags[%d]:  %d\n", i, whoopty.flags[i]);
	dprintf(1, "field width: %i\n", whoopty.fld_wdt);
	dprintf(1, "precision: %i\n", whoopty.precision);
	dprintf(1, "conversion: %c\n", whoopty.conversion);
	dprintf(1, "whoopty.lnglng: %lli\n", whoopty.lnglng);
	dprintf(1, "whoopty.unlnglng: %u\n", whoopty.un_lnglng);
	dprintf(1, "whoopty.character: %c\n", whoopty.character);
	dprintf(1, "whoopty.string: %s\n", whoopty.string);
	dprintf(1, "whoopty.ptr: %lu\n", whoopty.ptr);
	dprintf(1, "--------------------------------------\n");
}

int charput(char *character, int nb_char, bool reset)
{
	static int ret = 0;

	if (reset == 1)
		ret = 0;
	if (nb_char > 0)
	{
		ret += nb_char;
		write(1, character, nb_char);
	}
	return (ret);
}

conv def_type(conv whoopty, va_list *ap)
{
	if (whoopty.conversion == 'd' || whoopty.conversion == 'i')
		whoopty.lnglng = va_arg(*ap, int);
	else if (whoopty.conversion == 's')
	{
		whoopty.string = va_arg(*ap, char*);
		if (whoopty.string == NULL)
			whoopty.string = "(null)";
	}
	else if (whoopty.conversion == 'c')
		whoopty.character = (char)va_arg(*ap, int);
	else if (whoopty.conversion == 'x' || whoopty.conversion == 'X' || whoopty.conversion == 'o' || whoopty.conversion == 'u')
		whoopty.un_lnglng = va_arg(*ap, unsigned int);
	else if (whoopty.conversion == 'p')
		whoopty.ptr = (unsigned long)va_arg(*ap, void*);
	return (whoopty);
}

void conv_bridge(conv whoopty, char c)
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
		print_nb(whoopty.ptr, 16, whoopty);
	}
	else if (whoopty.conversion == 's')
	{
		if (whoopty.flags[2] == 0)
			draw_field(whoopty, -1, 0);
		charput(whoopty.string, ft_small_nb(ft_strlen(whoopty.string), whoopty.precision), 0);
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

void flag_peacemaker(bool *flags)
{
	if (flags[2] == 1)
		flags[1] = 0;
	if (flags[4] == 1)
		flags[3] = 0;
}

int ft_printf(const char *input, ...)
{
	va_list ap;
	int i;
	conv whoopty;

	if (!*input)
		return (0);
	i = 0;
	va_start(ap, input);
	charput(NULL, 0, 1);
	while (input[i])
	{
		if (input[i] != '%' && (i = i + 1))
			charput((char*)&input[i - 1], 1, 0);
		else if (input[i + 1] == '%')
		{
			charput("%", 1, 0);
			i += 2;
		}
		else
		{
			i++;
			ft_bzero(&whoopty, sizeof(whoopty));
			whoopty.precision = -1;
			i += ft_printf_parse(&whoopty, input + i, &ap);
			if (whoopty.fld_wdt < 0)
			{
				whoopty.fld_wdt *= -1;
				whoopty.flags[2] = 1;
			}
			flag_peacemaker(whoopty.flags);
			if (whoopty.conversion == 0 && whoopty.flags[2] == 1 && (i = i + 1))
				charput((char*)&input[i - 1], 1, 0);
			whoopty = def_type(whoopty, &ap);
			//print_conv(whoopty);
			conv_bridge(whoopty, input[i]);
		}
	}
	va_end(ap);
	return (charput(NULL, 0, 0));
}

//void test_fct(conv *whoopty, int arg_ct, ...)
//{
//	va_list ap;
//
//	va_start(ap, arg_ct);
//	whoopty->lnglng = va_arg(ap, int);
//	printf("arg.lnglng = %lld\n", whoopty->lnglng);
//	whoopty->lnglng = va_arg(ap, int);
//	printf("arg.lnglng = %lld\n", whoopty->lnglng);
//	whoopty->lnglng = va_arg(ap, long);
//	printf("arg.lnglng = %lld\n", whoopty->lnglng);
//	va_end(ap);
//}

//int main(int argc, char **argv)
//{
//	int integer;
//	long long longteger;
//	short shorteger;
////	int conv_len = 0;
//
//	(void)argc;
////	conv_len = sizeof(conversion);
//	shorteger = 32332;
//	longteger = 321432144324231;
//	integer = 1232132231;
////	(void)argc;
////	conversion.precision = atoi(argv[2]);
////	dprintf(1, "str: ");
////	printf("%s\n", argv[1]);
////	dprintf(1, "\nchar: ");
////	ft_putchar(argv[1][0]);
////	printf("\nstring with 0 precision: ");
////	printf("%.s\n", "ggsdafew");
////
////	test_fct(&conversion, 1, shorteger, integer, longteger);
////	ft_printf(argv[1], argv[2], ft_atoi(argv[3]), ft_atoi(argv[4]));
////	printf("%%\n");
////	ft_printf(argv[1], atoi(argv[2]));
////	printf("%%\n");
//	printf(argv[1], atoi(argv[2]));
//	printf("%%\n");
////	printf("return :%d\n", printf("%s\n", argv[1]));
//	return (0);
//}
