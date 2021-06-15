/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:29 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/15 19:51:29 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(int argc, char **argv)
{
	int ret;
	int ret2;
	conv whoopty;

	dprintf(1, "my_printf: ");
	ret = ft_printf(argv[1], "hi low");
	printf("%%\n");
	printf("rl_printf: ");
	ret2 = printf(argv[1], "hi low");
	printf("%%\n");
	printf("my_printf: %d\n", ret);
	printf("rl_printf: %d\n", ret2);
	printf("--------------------------------------------------\n");
//	dprintf(1, "my_printf: ");
//	ret = ft_printf(argv[1], 1);
//	printf("%%\n");
//	printf("rl_printf: ");
//	ret2 = printf(argv[1], 1);
//	printf("%%\n");
//	printf("my_printf: %d\n", ret);
//	printf("rl_printf: %d\n", ret2);

}
//		TEST(13, print(" %p %p ", -9223372036854775808, 9223372036854775807));
//		TEST(14, print(" %p %p ", -2147483648, 2147483647));
//		TEST(15, print(" %p %p ", 0, -18446744073709551615));
//		p
//		13
//		15
//
