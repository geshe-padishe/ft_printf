/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:08:29 by ngenadie          #+#    #+#             */
/*   Updated: 2021/06/07 13:04:50 by ngenadie         ###   ########.fr       */
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
	ret = ft_printf(argv[1], -9223372036854775808, 9223372036854775807);
	printf("%%\n");
	printf("rl_printf: ");
	ret2 = printf(argv[1], -9223372036854775808, 9223372036854775807);
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

//		p
//		13
//		15
//
