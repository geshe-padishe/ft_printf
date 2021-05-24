/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:07:53 by ngenadie          #+#    #+#             */
/*   Updated: 2021/05/24 19:09:36 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include "ft_printf.h"

int charput(char *character, int nb_char)
{
	static int ret = 0;

	if (nb_char > 0)
	{
		ret += nb_char;
		write(1, character, nb_char);
	}
	return (ret);
}

//void print_sc(char *flags, char conversion, int precision, va_list ap)
//{
//	if (conversion == 's')
//		print_str(str, precision);
//	if (conversion == 'c')
//		ft_putchar(c);
//}

conv def_type(conv whoopty, va_list *ap)
{
	if (whoopty.conversion == 'd' || whoopty.conversion == 'i' || whoopty.conversion == 'c')
		whoopty.lnglng = va_arg(*ap, int);
	else if (whoopty.conversion == 's')
		whoopty.string = va_arg(*ap, char*);
	else if (whoopty.conversion == 'c')
		whoopty.character = (char)va_arg(*ap, int);
	else
		whoopty.un_lnglng = va_arg(*ap, unsigned long long);
	return (whoopty);
}

void conv_bridge(conv whoopty)
{
	if (whoopty.conversion == 'd' || whoopty.conversion == 'i')
		print_nb(whoopty.lnglng, 10, whoopty);
	else if (whoopty.conversion == 'u')
		print_nb(whoopty.un_lnglng, 10, whoopty);
	else if (whoopty.conversion == 'x')
		print_nb(whoopty.un_lnglng, 16, whoopty);
	else if (whoopty.conversion == 'X')
		print_nb(whoopty.un_lnglng, -16, whoopty);
	else if (whoopty.conversion == 'o')
		print_nb(whoopty.un_lnglng, 8, whoopty);
	else if (whoopty.conversion == 's')
	{
		if (whoopty.flags[2] == 1)
			draw_field(whoopty, 0, 0);
		charput(whoopty.string, whoopty.precision);
		if (whoopty.flags[2] == 0)
			draw_field(whoopty, 0, 0);
	}
	else if (whoopty.conversion == 'c')
	{
		if (whoopty.flags[2] == 1)
			draw_field(whoopty, 0, 0);
		charput(&whoopty.character, 1);
		if (whoopty.flags[2] == 0)
			draw_field(whoopty, 0, 0);
	}
}

int ft_printf(const char *input, ...)
{
	va_list ap;
	int i;
	conv whoopty;


	i = 0;
	va_start(ap, input);
	while (input[i])
	{
		if (input[i] != '%')
			write(1, &input[i], 1);
		else
		{
			ft_bzero(&whoopty, sizeof(whoopty));
			whoopty.precision = 1;
			if ((ft_printf_parse(&whoopty, input, &ap)) == -1)
				return (-1);
			whoopty = def_type(whoopty, &ap);
			conv_bridge(whoopty);
		}
		i++;
	}
	va_end(ap);
	return (charput(NULL, 0));
}

//int print_conv(conv *whoopty)
//{
//	int i = 0;
//	for(i = 0; i < 5; i++)
//		printf("flags[%d]:  %d\n", i, whoopty->flags[i]);
//	printf("field width: %i\n", whoopty->fld_wdt);
//	printf("precision: %i\n", whoopty->precision);
//	printf("conversion: %c\n", whoopty->conversion);
//	printf("whoopty.lnglng: %lli\n", whoopty->lnglng);
//	printf("whoopty.unlnglng: %lli\n", whoopty->un_lnglng);
//	return 0;
//}

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
